#pragma once
#include "Bootil/Bootil.h"

namespace tthread
{
	class thread;
	class fast_mutex;
};

namespace Bootil
{
	namespace Threads
	{
		class BOOTIL_EXPORT Thread
		{
			public:

				Thread();
				virtual ~Thread();

				virtual void Run() = 0;

				bool Running();

				bool StartInThread();

				void Lock();
				void Unlock();
				void TryLock();

				void Join();

				virtual void OnThreadFinished(){};

			protected:

				static void RunInThread( void* pArg );

				tthread::thread*		m_pThread;
				Threads::Mutex			m_Mutex;
				bool					m_bRunning;
		};
	}
}

