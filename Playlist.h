#pragma once

#include <string>
 
using namespace std;

class PlaylistNode {
private:
    string uniqueID = "none";
    string songName = "none";
    string artistName = "none";
    int songLength = 0;
    PlaylistNode* nextNodePtr = 0;
public:
    void InsertAfter(PlaylistNode* nextNode);
    void SetNext(PlaylistNode* ptr);
    string GetID();
    string GetSongName();
    string GetArtistName();
    int GetSongLength();
    PlaylistNode* GetNext();
    void PrintPlaylistNode();
    PlaylistNode(string a = "none", string b = "none", string c = "none", int d = 0, PlaylistNode* ptr = 0) {
        uniqueID = a;
        songName = b;
        artistName = c;
        songLength = d;
        nextNodePtr = ptr;
    }
};