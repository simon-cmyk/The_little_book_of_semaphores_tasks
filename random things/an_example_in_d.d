T allocate(int priority){
        mtx.wait();
        if(busy){
            mtx.notify();
            numWaiting[priority]--;
            sems[priority].wait();
        }
        busy = true;
        mtx.notify();
        return value;
    }
    
void deallocate(T v){
    mtx.wait();
    busy = false;
    if(numWaiting[1] < 0){
        numWaiting[1]++;
        sems[1].notify();
    } else if(numWaiting[0] < 0){
        numWaiting[0]++;
        sems[0].notify();
    } else {
        mtx.notify();
    }
    value = v;
}

// with cond variables (priority queue)

T allocate(int id, int priority){
        mtx.lock();
        queue.insert(id, priority);
        while(queue.front != id){
            cond.wait();
        }
        mtx.unlock();
        return value;
    }
    
void deallocate(T v){
    mtx.lock();
    queue.popFront();
    cond.notifyAll();
    mtx.unlock();
    value = v;
}