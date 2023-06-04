Protected body Table is

entry WakeMatchesThread when TobaccoOnTable and PaperOnTable
begin
    TobaccoOnTable := false;
    PaperOnTable := false;
end

procedure Tobacco()
begin
    TobaccoOnTable := True
end

procedure Matches()
begin
    MatchesOnTable := True
end

entry EmptyTableCalledByAgent when TobaccoOnTable = False and 
MatchesOnTable = False and PaperOnTable = False
begin
    -- Randomly spawn two. 
end

private
    MatchesOnTable: Boolean := False
end Table;