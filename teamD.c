/** 
 * @brief compare rebounds per game for two teams
 * @param team1 the ID for team1 for the game being analyzed
 * @param team2 the ID for team2 for the game being analyzed
 * @param homeIDs the homeIDs for all games
 * @param awayIDs the awayIDs for all games
 * @param homeRebounds the homeRebound values for all games
 * @param awayRebounds the awayRebound values for all games
 * @param num_games the number of games being analyzed (the length of the parallel arrays)
 * @return the difference in rebounds per game between the home and away team
 * The differential will be positive if team 1 averages more rebounds per game, and vice versa
 */ 
double reboundsPerGameComparison(int team1, int team2, int* homeIDs, int* awayIDs, int* homeRebounds, int* awayRebounds, int num_games){
    int reboundsHomeSum = 0;
    int reboundsAwaySum = 0;
    int gamesCountedHome = 0;
    int gamesCountedAway = 0;

    for(int i=0;i<num_games;i++){
        if (team1 == homeIDs[i]){
            reboundsHomeSum += homeRebounds[i];
            gamesCountedHome++;
        }else if (team1 == awayIDs[i]){
            reboundsHomeSum += awayRebounds[i];
            gamesCountedHome++;
        }

        if (team2 == homeIDs[i]){
            reboundsAwaySum += homeRebounds[i];
            gamesCountedAway++;
        }else if (team2 == awayIDs[i]){
            reboundsAwaySum += awayRebounds[i];
            gamesCountedAway++;
        }
    }

    double homeReboundsAvg = (double)reboundsHomeSum/(double)gamesCountedHome;
    double awayReboundsAvg = (double)reboundsAwaySum/(double)gamesCountedAway;

    return homeReboundsAvg - awayReboundsAvg;
}