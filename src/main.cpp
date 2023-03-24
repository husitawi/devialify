#include <iostream>
#include "mediaPlayer.h"

int main() {
    auto& player = Devialify::MediaPlayer::instance();
    while (true) 
    {
        std::cout << std::endl;
        std::cout << "Enter command (p: play, s: pause, r: resume, n: skip, b: back, sh: shuffle, rp: repeat, a: add track, rt: remove track, rd: remove duplicates, ti: show track info, pi: show playlist info, ap: add playlist, rmp: remove playlist, sp: select playlist, pai: show all playlists info, rn: rename playlist, q: quit): ";
        std::string command;
        getline(std::cin, command);
        
        std::cout << std::endl;

        if (command == "p") {
            player.play();
        } else if (command == "s") {
            player.pause();
        } else if (command == "r") {
            player.resume();
        } else if (command == "n") {
            player.skip();
        } else if (command == "b") {
            player.back();
        } else if (command == "sh") {
            player.shuffle();
        } else if (command == "rp") {
            player.repeat();
        } else if (command == "a") {
            player.addTrack();
        } else if (command == "rt") {
            player.removeTrack();
        } else if (command == "rd") {
            player.removeDuplicates();
        } else if (command == "ti") {
            player.showTrackInfo();
        } else if (command == "pi") {
            player.showPlaylistInfo();
        } else if (command == "ap") {
            player.addPlaylist();
        } else if (command == "rmp") {
            player.removePlaylist();
        } else if (command == "sp") {
            player.selectPlaylist();
        } else if (command == "pai") {
            player.showPlaylists();
        } else if (command == "rn") {
            player.renamePlaylist();
        }
        else if (command == "q") {
            break;
        } else {
            std::cout << "Invalid command." << std::endl;
        }
    }
    return 0;
}