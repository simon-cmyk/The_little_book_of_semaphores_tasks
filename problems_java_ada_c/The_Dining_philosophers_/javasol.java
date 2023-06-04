class Table(){
    private int seats = 5;
    private int[] forks; 

    int left(int i) { return i; }
    int right(int i) { return (i+1)%seats; }


    syncronized void get_fork(i){
        if(i == 0){
            // leftie chap
            while(forks[left(i)] == 1) wait();
            forks[left(i)] = 1;
            while(forks[right(i)] == 1) wait();
            forks[right(i)] = 1;
        } else {
            while(forks[right(i)] == 1) wait();
            forks[right(i)] = 1;
            while(forks[left(i)] == 1) wait();
            forks[left(i)] = 1;
        }
    };

    syncronized void put_fork(i){
            // leftie chap
            forks[left(i)] = 0;
            forks[right(i)] = 0;
            notifyAll();
    };

    void philosopher(int i) {
        while(true){
            think();
            get_fork(i);
            eat();
            put_fork(i);
        }
    }




}
