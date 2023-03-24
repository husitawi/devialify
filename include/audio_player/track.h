#pragma once

#include <string>

namespace Devialify
{

/*
 * A Track is a single audio file.
 */
class Track final
{
    public:

        const std::string& title() const;
        const std::string& artist() const;
        const std::string& codec() const;
        int duration() const;
        const std::string id() const;
        std::string toString() const;

        Track() = delete; // No default constructor
        explicit Track(const std::string& title, const std::string& artist, int duration, const std::string& codec);

        friend bool operator==(const Track& l, const Track& r);

    private:
        std::string m_title;
        std::string m_artist;
        std::string m_codec;
        int m_duration; // in seconds
};

// Generate a hash for Track
struct TrackHash {
    std::size_t operator()(const Track& track) const {
        std::size_t h1 = std::hash<std::string>()(track.title());
        std::size_t h2 = std::hash<std::string>()(track.artist());
        std::size_t h3 = std::hash<std::string>()(track.codec());
        std::size_t h4 = std::hash<int>()(track.duration());
        return h1 ^ (h2 << 1) ^ (h3 << 2) ^ (h4 << 3);
    }
};

}
