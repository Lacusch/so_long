# TO DO

Started 2. of November

- ~~Use get next line to parce a map~~
- ~~Set up a stuct for the player~~
- ~~Set up the elements (line by line)~~
  - ~~They should be in a char array~~
  - ~~Each one should have an instance at the correct cordinate~~
  - ~~Expamle: 0 *48, 1*48, 2*48, etc.~~
- ~~Set up the player to move by 48~~
- ~~Set up map elements~~
  1. ~~Border~~
  2. ~~Collectable~~
  3. ~~Start~~
  4. ~~Exit~~
- Set up collition
  1. ~~you should't be able to move over walls~~
  2. ~~you should collect collectables~~
  3. ~~should exit at exit~~
- Check for a valid map
  1. ~~Check extention (.bar)~~
  2. ~~At least 1 Collectable (C) and no more that one player (P) and exit(E)~~
  3. ~~Check recktengular map~~
  4. ~~Check wall~~
  5. ~~Empy map~~
  6. ~~Different characters~~
  7. ~~Map uncompletable~~
  - ~~flood_fill function~~
  - ~~add return to 1 / 1 to flood_fill and print error~~
  - ~~set player location sooner in the loop~~
  - debug leaks and crashes
    + Invalid read /write at big string, debug /rewrite function
	+ Read returns 0 if we get to the end of file !!!!!!
    + free the malloc with 0 size then free the split
  8. Handle big maps ???
  9. reduce function size + use less than 3 variables
- ~~Check for leaks and smooth movements~~
- ~~Sometimes it randomly crashes !!!~~
