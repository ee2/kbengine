namespace KBEngine { 
namespace thread
{

INLINE bool ThreadPool::isInitialize(void)const
{ 
	return isInitialize_; 
}

INLINE bool ThreadPool::isBusy(void)const
{
	return bufferedTaskList_.size() > THREAD_BUSY_SIZE;
}	

INLINE bool ThreadPool::isThreadCountMax(void)const
{
	return currentThreadCount_ >= maxThreadCount_;	
}

INLINE uint32 ThreadPool::getCurrentThreadCount(void)const
{ 
	return currentThreadCount_; 
}

INLINE uint32 ThreadPool::getCurrentFreeThreadCount(void)const
{ 
	return currentFreeThreadCount_; 
}

INLINE bool ThreadPool::isDestroyed()const 
{ 
	return isDestroyed_; 
}

ThreadPool* TPThread::threadPool()
{
	return threadPool_;
}

INLINE uint32 ThreadPool::bufferTaskSize()const
{
	return bufferedTaskList_.size();
}

INLINE std::queue<thread::TPTask*>& ThreadPool::bufferedTaskList()
{
	return bufferedTaskList_;
}

INLINE void ThreadPool::lockBufferedTaskList()
{
	THREAD_MUTEX_LOCK(bufferedTaskList_mutex_);
}

INLINE void ThreadPool::unlockBufferedTaskList()
{
	THREAD_MUTEX_UNLOCK(bufferedTaskList_mutex_);
}
	
INLINE uint32 ThreadPool::finiTaskSize()const
{
	return finiTaskList_count_;
}

INLINE THREAD_ID TPThread::getID(void)const
{
	return tidp_;
}

INLINE void TPThread::setID(THREAD_ID tidp)
{
	tidp_ = tidp;
}

INLINE TPTask* TPThread::getTask(void)const
{
	return currTask_;
}

INLINE void TPThread::setTask(TPTask* tpt)
{
	currTask_ = tpt;
}

INLINE int TPThread::getState(void)const
{
	return state_;
}


}
}
