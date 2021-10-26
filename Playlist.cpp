#include <string>
#include <iostream>
#include "Playlist.h"

using namespace std;

void PlaylistNode::InsertAfter(PlaylistNode* nextNode) {
	PlaylistNode* temp = 0;
	temp = this->nextNodePtr;
	this->nextNodePtr = nextNode;
	nextNode->nextNodePtr = temp;
}
void PlaylistNode::SetNext(PlaylistNode* ptr) {
	nextNodePtr = ptr;
}
string PlaylistNode::GetID() {
	return uniqueID;
}
string PlaylistNode::GetSongName() {
	return songName;
}
string PlaylistNode::GetArtistName() {
	return artistName;
}
int PlaylistNode::GetSongLength() {
	return songLength;
}
PlaylistNode* PlaylistNode::GetNext() {
	return nextNodePtr;
}
void PlaylistNode::PrintPlaylistNode() {
	cout << "Unique ID: " << uniqueID << endl;
	cout << "Song Name: " << songName << endl;
	cout << "Artist Name: " << artistName << endl;
	cout << "Song Length (in seconds): " << songLength << endl << endl;
}