#include "playlist.h"
#include <random>
#include <algorithm>
#include <iostream>
#include <unordered_set>

namespace Devialify
{

Playlist::Playlist(const std::string& name)
    : m_name(name)
{}

const std::string& Playlist::name() const
{
    return m_name;
}

void Playlist::rename(const std::string& name)
{
    m_name = name;
}

void Playlist::addTrack(const Track& track)
{
    m_tracks.push_back(track);
}   

void Playlist::removeTrack(const std::string& id)
{
    const auto it = std::find_if(m_tracks.begin(), m_tracks.end(), [&id](const Track& track) { return track.id() == id; });
    if(it != m_tracks.end())
    {
        m_tracks.erase(it);
    }
}

void Playlist::removeTrack(const int index)
{
    if (index >= 0 && index < m_tracks.size())
    {
        m_tracks.erase(m_tracks.begin() + index);
    }
}

void Playlist::clear()
{
    m_tracks.clear();
}

void Playlist::removeDuplicates()
{
    // This approach is used to not mess the order of the playlist
    // If order is not important, we can std::sort the playlist and then use std::unique
    std::unordered_set<Track, TrackHash> seen;
    auto end = std::remove_if(m_tracks.begin(), m_tracks.end(), [&](Track& track) {
        return !seen.insert(track).second;
    });
    m_tracks.erase(end, m_tracks.end());
}

void Playlist::showInfo() const {
    std::cout << "Playlist information:" << std::endl;
    std::cout << "Total tracks: " << m_tracks.size() << std::endl;
    int total_duration = 0;
    for (auto track : m_tracks) {
        total_duration += track.duration();
    }
    const int hours = total_duration / 3600;
    const int minutes = (total_duration % 3600) / 60;
    const int seconds = total_duration % 60;
    std::cout << "Total duration: " << hours << "h " << minutes << "m " << seconds << "s" << std::endl;

    std::cout << "Tracks:" << std::endl;
    int index = 1;
    for (auto track : m_tracks) {
        std::cout << std::to_string(index) + ". " + track.toString() << std::endl;
    }
}

size_t Playlist::size() const
{
    return m_tracks.size();
}

bool Playlist::isEmpty() const
{
    return m_tracks.empty();
}

const Track& Playlist::operator[](int index) const
{
    return m_tracks[index];
}

void Playlist::shuffle()
{
    std::shuffle(m_tracks.begin(), m_tracks.end(), std::random_device());
}

std::vector<Track> Playlist::find(const std::string& titleFilter) const
{
    std::vector<Track> matchingTracks{};
    for (const auto& track : m_tracks) {
        if (track.title().find(titleFilter) != std::string::npos) {
            matchingTracks.push_back(track);
        }
    }
    return matchingTracks;
}

}