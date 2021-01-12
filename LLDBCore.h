//
// Created by w4264 on 2021/1/8.
//

#pragma once
#include <QThread>
#include <lldb/API/LLDB.h>

class LLDBCore : public QThread
{
	Q_OBJECT

public:
	explicit LLDBCore(QString path, QString args);

	static bool init();

signals:

	void debugeeExited(int status);

protected:
	void run() override;

private:
	QString m_path;
	QString m_args;

	lldb::SBDebugger m_debugger;
	lldb::SBListener m_listener;
	lldb::SBTarget m_target;
	lldb::SBProcess m_process;
	lldb::SBEvent m_event;
};


