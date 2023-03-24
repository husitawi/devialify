#include "mediaPlayer.h"
#include <iostream>

namespace Devialify
{

MediaPlayer &MediaPlayer::instance(const std::string &defaultPlaylist)
{
    static MediaPlayer instance(defaultPlaylist);
    return instance;
}

MediaPlayer::MediaPlayer(const std::string &defaultPlaylist)
{
    m_playlists.push_back(Playlist(defaultPlaylist));
}

void MediaPlayer::play()
{
    if (!m_isPlaying && !m_isPaused)
    {
        auto& playlist = m_playlists[m_currentPlaylistIndex];
        if (playlist.isEmpty())
        {
            std::cout << "Playlist is empty." << std::endl;
            return;
        }

        if (m_currentTrackIndex == -1)
        {
            // Start playing from the beginning of the playlist
            m_currentTrackIndex = 0;
        }
        std::cout << "Playing: " << playlist[m_currentTrackIndex].title() << std::endl;
        m_isPlaying = true;
    }
    else
    {
        std::cout << "Already playing." << std::endl;
    }
}

void MediaPlayer::pause()
{
    if (m_isPlaying && !m_isPaused)
    {
        std::cout << "Paused." << std::endl;
        m_isPaused = true;
    }
    else
    {
        std::cout << "Cannot pause, not playing or already paused." << std::endl;
    }
}

void MediaPlayer::resume()
{
    if (m_isPlaying && m_isPaused)
    {
        std::cout << "Resumed." << std::endl;
        m_isPaused = false;
    }
    else
    {
        std::cout << "Cannot resume, not playing or not paused." << std::endl;
    }
}

void MediaPlayer::skip()
{
    if (m_currentTrackIndex == -1)
    {
        std::cout << "Cannot skip, not playing anything." << std::endl;
        return;
    }

    if(m_isRepeat)
    {
        std::cout << "Cannot skip, repeat is on." << std::endl;
        return;
    }
    
    auto& playlist = m_playlists[m_currentPlaylistIndex];
    if (m_currentTrackIndex == playlist.size() - 1)
    {
        std::cout << "End of playlist." << std::endl;
        m_currentTrackIndex = -1;
        m_isPlaying = false;
        m_isPaused = false;
        return;
    }

    ++m_currentTrackIndex;
    std::cout << "Skipping to next track: " << playlist[m_currentTrackIndex].title() << std::endl;
}

void MediaPlayer::back()
{
    if (m_currentTrackIndex == -1)
    {
        std::cout << "Cannot go back, not playing anything." << std::endl;
        return;
    }

    if(m_isRepeat)
    {
        std::cout << "Cannot go back, repeat is on." << std::endl;
        return;
    }

    auto& playlist = m_playlists[m_currentPlaylistIndex];
    if (m_currentTrackIndex == 0)
    {
        std::cout << "Beginning of playlist." << std::endl;
        return;
    }

    --m_currentTrackIndex;
    std::cout << "Going back to previous track: " << playlist[m_currentTrackIndex].title() << std::endl;
}

void MediaPlayer::shuffle()
{
    auto& playlist = m_playlists[m_currentPlaylistIndex];
    if (playlist.isEmpty()) {
        std::cout << "Playlist is empty." << std::endl;
        return;
    }

    if (playlist.size() == 1) {
        std::cout << "Playlist only has 1 track." << std::endl;
        return;
    }

    playlist.shuffle();
    std::cout << "Shuffled." << std::endl;
}

void MediaPlayer::repeat()
{
    m_isRepeat = !m_isRepeat;
    std::cout << "Repeat is now " << (m_isRepeat ? "enabled" : "disabled") << std::endl;
}

void MediaPlayer::addTrack()
{
    std::string title, artist, codec;
    int duration;
    std::cout << "Enter track information:" << std::endl;
    std::cout << "Title: ";
    getline(std::cin, title);
    std::cout << "Artist: ";
    getline(std::cin, artist);
    std::cout << "Duration (in seconds): ";
    std::cin >> duration;
    std::cin.ignore(); // Ignore the newline character left by cin
    std::cout << "Codec: ";
    getline(std::cin, codec);
    auto track = Track{title, artist, duration, codec};

    auto& playlist = m_playlists[m_currentPlaylistIndex];
    playlist.addTrack(track);
    std::cout << "Track added to playlist." << std::endl;
}

void MediaPlayer::removeTrack()
{
    auto& playlist = m_playlists[m_currentPlaylistIndex];
    if (playlist.isEmpty())
    {
        std::cout << "Playlist is empty." << std::endl;
        return;
    }

    std::cout << "Enter track number to remove (1-" << playlist.size() << "): ";
    int index;
    std::cin >> index;
    std::cin.ignore(); // Ignore the newline character left by cin

    if (index < 1 || index > playlist.size())
    {
        std::cout << "Invalid track number." << std::endl;
        return;
    }

    if(m_currentTrackIndex == index - 1)
    {
        std::cout << "Cannot remove currently playing track." << std::endl;
        return;
    }

    playlist.removeTrack(index - 1);
    std::cout << "Track removed from playlist." << std::endl;
}

void MediaPlayer::addPlaylist()
{
    std::string name;
    std::cout << "Enter playlist name: ";
    getline(std::cin, name);
    m_playlists.push_back(Playlist(name));
    std::cout << "Playlist added." << std::endl;
}

void MediaPlayer::removePlaylist()
{
    if (m_playlists.size() == 1)
    {
        std::cout << "Cannot remove only playlist." << std::endl;
        return;
    }

    std::cout << "Enter playlist number to remove (1-" << m_playlists.size() << "): ";
    int index;
    std::cin >> index;
    std::cin.ignore(); // Ignore the newline character left by cin

    if (index < 1 || index > m_playlists.size())
    {
        std::cout << "Invalid playlist number." << std::endl;
        return;
    }

    if(m_currentPlaylistIndex == index - 1)
    {
        std::cout << "Cannot remove currently playing playlist." << std::endl;
        return;
    }

    m_playlists.erase(m_playlists.begin() + index - 1);
    std::cout << "Playlist removed." << std::endl;
}

void MediaPlayer::selectPlaylist()
{
    if (m_playlists.size() == 1)
    {
        std::cout << "Only one playlist exists." << std::endl;
        return;
    }

    std::cout << "You currently have selected playlist: " << m_playlists[m_currentPlaylistIndex].name() << std::endl;
    std::cout << "Enter playlist number to select (1-" << m_playlists.size() << "): ";
    int index;
    std::cin >> index;
    std::cin.ignore(); // Ignore the newline character left by cin

    if (index < 1 || index > m_playlists.size())
    {
        std::cout << "Invalid playlist number." << std::endl;
        return;
    }

    if(m_currentPlaylistIndex == index - 1)
    {
        std::cout << "Playlist already selected." << std::endl;
        return;
    }

    m_currentPlaylistIndex = index - 1;
    std::cout << "Selected playlist: " << m_playlists[m_currentPlaylistIndex].name() << std::endl;

    m_isPlaying = false;
    m_isPaused = false;
    m_isRepeat = false;
    m_currentTrackIndex = -1;
}

void MediaPlayer::removeDuplicates()
{
    auto& playlist = m_playlists[m_currentPlaylistIndex];
    if (playlist.isEmpty())
    {
        std::cout << "Playlist is empty." << std::endl;
        return;
    }

    playlist.removeDuplicates();
    std::cout << "Duplicates removed." << std::endl;
}

void MediaPlayer::showTrackInfo() const
{
    auto& playlist = m_playlists[m_currentPlaylistIndex];
    if (playlist.isEmpty())
    {
        std::cout << "Playlist is empty." << std::endl;
        return;
    }

    std::cout << "Enter track number to show info (1-" << playlist.size() << "): ";
    int index;
    std::cin >> index;
    std::cin.ignore(); // Ignore the newline character left by cin

    if (index < 1 || index > playlist.size())
    {
        std::cout << "Invalid track number." << std::endl;
        return;
    }

    auto& track = playlist[index - 1];
    std::cout << "Track " << index << " info:" << std::endl;
    std::cout << track.toString() << std::endl;
}

void MediaPlayer::showPlaylistInfo() const
{
    std::cout << "Enter playlist number to show info (1-" << m_playlists.size() << "): ";
    int index;
    std::cin >> index;
    std::cin.ignore(); // Ignore the newline character left by cin

    if (index < 1 || index > m_playlists.size())
    {
        std::cout << "Invalid playlist number." << std::endl;
        return;
    }

    auto &playlist = m_playlists[index - 1];
    if (playlist.isEmpty())
    {
        std::cout << "Playlist is empty." << std::endl;
        return;
    }
    playlist.showInfo();
}

void MediaPlayer::showPlaylists() const
{
    if (m_playlists.empty())
    {
        std::cout << "No playlists." << std::endl;
        return;
    }

    std::cout << "Playlists:" << std::endl;
    for (int index = 0; index < m_playlists.size(); ++index)
    {
        std::cout << index + 1 << ". " << m_playlists[index].name() << std::endl;
    }
}

void MediaPlayer::renamePlaylist()
{
    std::cout << "Enter playlist number to rename (1-" << m_playlists.size() << "): ";
    int index;
    std::cin >> index;
    std::cin.ignore(); // Ignore the newline character left by cin

    if (index < 1 || index > m_playlists.size())
    {
        std::cout << "Invalid playlist number." << std::endl;
        return;
    }

    std::string name;
    std::cout << "Enter new name: ";
    getline(std::cin, name);
    m_playlists[index - 1].rename(name);
    std::cout << "Playlist renamed." << std::endl;
}

}