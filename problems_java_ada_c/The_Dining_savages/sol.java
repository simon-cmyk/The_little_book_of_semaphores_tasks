class Pot() {
    private int servings = M;

    // in reality this equals eat function
    synchronized void get_serving() {
        if(servings > 0) servings--;
        else{
            awakeCook = True;
            notifyAll();
            while(servings == 0) wait();
            servings--;
        }
    }

    synchronized void refill() {
        while(!awakeCook) wait();
        servings = M;
        awakeCook = False;
        notifyAll();
    }
}