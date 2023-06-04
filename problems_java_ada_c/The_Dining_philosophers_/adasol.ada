Protected Object Tables is
private seats: Natural := 5;
private seated: Natural := 0;

function getLeftSeat(i : Natural) is
    return i; 
end getLeftSeat;

function getRightSeat(i : Natural) is
    return (i + 1)%seats; 
end getRightSeat;

procedure GetLefFork(i : Natural) is 
entry guard when forks(i) = false is

end guard;

procedure GetRightFork(i : Natural) is
entry guard when forks(getRightSeat(i)) = false is

procedure sitDown() is
entry guard when seats /= (seats-1) is
    sitDown();
    seated := seated + 1;
end guard;

procedure standUp() is
entry guard when seats /= 0 is
    seated := seated - 1;
end guard;
end Tables;

// We must guarantee that the phi