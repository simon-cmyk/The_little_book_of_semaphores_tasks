protected type Resource is
        entry allocateHigh(val: out IntVec.Vector);
        entry allocateLow(val: out IntVec.Vector);
        procedure deallocate(val: IntVec.Vector);
    private
        value: IntVec.Vector;
        busy: Boolean := False;
    end Resource;
protected body Resource is

    entry allocateLow(val: out IntVec.Vector) when not busy and allocateHigh'Count = 0 is
    begin
        busy := True;
        --Put_Line("allocateLow");
        val := value;
    end allocateLow;

    entry allocateHigh(val: out IntVec.Vector) when not busy is
    begin
        busy := True;
        --Put_Line("allocateHigh");
        val := value;
    end allocateHigh;

    procedure deallocate(val: IntVec.Vector) is
    begin
        busy := False;
        --Put_Line("deallocate");
        value := val;
    end deallocate;

end Resource;