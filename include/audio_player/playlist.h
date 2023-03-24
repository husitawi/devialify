#pragma once

#include <vector>
#include <string>
#include "track.h"

namespace Devialify
{

class Playlist final
{
    public:

        const std::string& name() const;
        void rename(const std::string& name);

        void addTrack(const Track& track);
        void removeTrack(const std::string& id);
        void removeTrack(const int index);
        void removeDuplicates();
        void showInfo() const;
        void shuffle();
        
        void clear();
        size_t size() const;
        bool isEmpty() const;
        const Track& operator[](int index) const;
        
        explicit Playlist(const std::string& name);

    private:
        std::string m_name;
        std::vector<Track> m_tracks{};
};

}