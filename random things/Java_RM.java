synchronized allocate(){
    if(busy){
        queue.insertFirst(myThreadId);
        while(busy || queue.getFirst() != myThreadId) wait();
        queue.removeFirst();
    }
    busy = true;
    notifyAll() // If mult can be allocated at same time
}

synchronized free(){
    busy = false;
    notifyAll();
}