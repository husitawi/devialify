#include "track.h"
#include <cstring>

namespace Devialify
{

static std::string tolower(const std::string &original)
{
    std::string result{};
    result.resize(original.size());
    std::transform(original.begin(), original.end(), result.begin(), ::tolower);
    return result;
}

Track::Track(const std::string &title, const std::string &artist, const int duration, const std::string &codec)
    : m_title(tolower(title))
    , m_artist(tolower(artist))
    , m_duration(duration)
    , m_codec(codec)
{
}

Track::Track(const Track &other) 
    : m_title(other.m_title)
    , m_artist(other.m_artist)
    , m_duration(other.m_duration)
    , m_codec(other.m_codec)
{
}

Track& Track::operator=(Track&& other)
{
    m_title = std::move(other.m_title);
    m_artist = std::move(other.m_artist);
    m_duration = std::move(other.m_duration);
    m_codec = std::move(other.m_codec);
    return *this;
}


const std::string &Track::title() const
{
    return m_title;
}

const std::string &Track::artist() const
{
    return m_artist;
}

const std::string &Track::codec() const
{
    return m_codec;
}

int Track::duration() const
{
    return m_duration;
}

const std::string Track::id() const
{
    return m_title + " - " + m_artist;
}

std::string Track::toString() const
{
    return m_title + " - " + m_artist + " (" + std::to_string(m_duration) + "s)" + " [" + m_codec + "]";
}

}