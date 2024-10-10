/** 
 * @brief get point differential per game for one team
 * @param teamID the team being analyzed
 * @param homeIDs the homeIDs for all games
 * @param awayIDs the awayIDs for all games
 * @param homeScores the ptsHome values for all games
 * @param awayScores the ptsAway values for all games
 * @param num_games the number of games being analyzed (the length of the parallel arrays)
 * @return the point differential per game across all game for the team
 * The differential will be positive if the team has gotten more points per game than their opponents, and vice versa
 */ 
double pointDifferentialPerGameOneTeam(int teamID, int* homeIDs, int* awayIDs, int* homeScores, int* awayScores, int num_games){
    int pointDiff = 0;
    int gamesCounted = 0;

    for(int i=0;i<num_games;i++){
        if (teamID == homeIDs[i]){
            pointDiff += (homeScores[i]-awayScores[i]);
            gamesCounted++;
        }else if (teamID == awayIDs[i]){
            pointDiff += (awayScores[i]-homeScores[i]);
            gamesCounted++;
        }
    }

    double diffPerGame = (double)pointDiff/(double)gamesCounted;

    return diffPerGame;
}