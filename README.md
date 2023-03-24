## Devialify
Devialify - A Developer's Spotify 

<hr>

Since no restrictions were set, I made the app as simple as possible. In a nutshell: you can create playlists and add tracks to each playlist.
The rest of the API is to add/remove tracks, add/remove playlists, play/pause/back/skip tracks.
I beleive the code is self explanatory, the only meaningful note is that the MediaPlayer is a singleton. Beyond that, the main improvement I can imagine is how tracks are stored, in a more realistic scenario, tracks would be all be stored in some container and only tags would be shared with a certain playlist, given the fact that a single track can be available in many playlists.

<hr>

## Running The App

The app is a CMAKE project. That's the only pre-requisite needed to build/run the app. Assuming CMake is installed and exists in your PATH. Please run 
```python
python3 ./run.py
```

The script will automatically build and run the executable.
