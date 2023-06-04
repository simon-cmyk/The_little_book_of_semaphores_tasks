Protexted Object Pot is
    private servings: Natural := 10;

Procedure FillPot is when servings = 0 is
begin
    put_servingsinpot(10);
    servingsLeft = 10;
end FillPot;

Procedure GetServings is when servings /= 0 is
begin
    GetServing()
    servingsLeft := servingsLeft - 1;
end

function Eat is 
begin
    while True loop is
        GetServings();
        eat()
    end loop
end Eat;

function fill is 
begin
    while True loop is
        FillPot();
    end loop
end
end Pot;


-- Sverre solution
Protected Object Pot is
    private servingsLeft : Natural := 3;

entry eat when servingsLeft > 0 is
    servingsLeft := servingsLeft - 1;

entry cook when servingsLeft == 0 is
    servingsLeft := 3;
end Pot;

// Functions are read only so they are allowed to interleaved
// Select then abort 
// Would not be able to use parameter in guard. 