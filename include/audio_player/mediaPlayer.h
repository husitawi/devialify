#pragma once
#include "playlist.h"

namespace Devialify
{

class MediaPlayer final
{
public:
    void play();
    void pause();
    void resume();
    void skip();
    void back();
    void shuffle();
    void repeat();
    void addTrack();
    void removeTrack();
    void addPlaylist();
    void removePlaylist();
    void selectPlaylist();
    void removeDuplicates();
    void showTrackInfo() const;
    void showPlaylistInfo() const;
    void showPlaylists() const;
    void renamePlaylist();
    
    static MediaPlayer& instance(const std::string& defaultPlaylist = "Default");

    // Delete copy and move constructors and assign operators
    MediaPlayer() = delete;                               // Default contsurctor
    MediaPlayer(MediaPlayer const&) = delete;             // Copy constructor
    MediaPlayer(MediaPlayer&&) = delete;                  // Move constructor
    MediaPlayer& operator=(MediaPlayer const&) = delete;  // Copy assign
    MediaPlayer& operator=(MediaPlayer &&) = delete;      // Move assign

private:
    MediaPlayer(const std::string& defaultPlaylist);

    bool m_isPlaying = false;
    bool m_isPaused = false;
    bool m_isRepeat = false;
    int m_currentTrackIndex = -1;
    int m_currentPlaylistIndex = 0;
    std::vector<Playlist> m_playlists{};

};

}