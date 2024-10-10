/**
 * @brief compare assists per game for two teams
 * @param team1 the ID for team1 for the game being analyzed
 * @param team2 the ID for team2 for the game being analyzed
 * @param homeIDs the homeIDs for all games
 * @param awayIDs the awayIDs for all games
 * @param homeAssists the homeAssist values for all games
 * @param awayAssists the awayAssist values for all games
 * @param num_games the number of games being analyzed (the length of the parallel arrays)
 * @return the difference in assists per game between team 1 and team 2
 * The differential will be positive if team 1 averages more assists per game, and vice versa
 */
double assistsPerGameComparison(int team1, int team2, int* homeIDs, int* awayIDs, int* homeAssists, int* awayAssists, int num_games){
   
    // declare variables
    int team1TotalAssists = 0;
    int team2TotalAssists = 0;
    int gamesCountedHome = 0;
    int gamesCountedAway = 0;
    double assistsPerGameTeam1 = 0.0;
    double assistsPerGameTeam2 = 0.0;
    int i;
   
 
    // tally totals for each team
    for(i=0 ; i < num_games ; i++){
        if(homeIDs[i] == team1){
            team1TotalAssists += homeAssists[i];
            ++ gamesCountedHome;
        }
        if(awayIDs[i] == team1){
            team1TotalAssists += awayAssists[i];
            ++ gamesCountedAway;
        }
    }
   
    // assign
    assistsPerGameTeam1 = team1TotalAssists / (double)gamesCountedHome;
    assistsPerGameTeam2 = team1TotalAssists / (double)gamesCountedAway;
 
    double returnValue = 0.0;
    if (assistsPerGameTeam1 > assistsPerGameTeam2){
        returnValue = assistsPerGameTeam1 - assistsPerGameTeam2;
    }
    else if(assistsPerGameTeam2 > assistsPerGameTeam1){
        returnValue = assistsPerGameTeam2 - assistsPerGameTeam1;
    }
 
    return returnValue;
}