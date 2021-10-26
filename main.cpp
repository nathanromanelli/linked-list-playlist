#include <iostream>
#include <string>
#include "Playlist.h"
#include <algorithm>

using namespace std;

void DeleteNode(PlaylistNode** head, string id) {
	PlaylistNode* temp1 = *head;
	PlaylistNode* temp2 = (*head)->GetNext();
	if ((*head)->GetID() == id) {
		cout << '"' << (*head)->GetSongName() << '"' << " removed" << endl << endl;
		*head = (*head)->GetNext();
	}
	else {
		while (temp2 != 0) {
			if (temp2->GetID() == id) {
				cout << '"' << temp2->GetSongName() << '"' << " removed." << endl << endl;
				if (temp2->GetNext() != 0) {
					temp1->SetNext(temp2->GetNext());
				}
				else {
					temp1->SetNext(0);
				}
			}
			temp1 = temp1->GetNext();
			temp2 = temp2->GetNext();
		}
	}
}

void ChangeNode(int pos1, int pos2, PlaylistNode** head, PlaylistNode* tail) {
	pos1 = max(1, pos1);
	pos2 = max(1, pos2);
	PlaylistNode* temp1 = *head;
	PlaylistNode* temp2 = *head;
	PlaylistNode* temp = 0;

	//if moving head
	if (pos1 == 1) {
		cout << '"' << (*head)->GetSongName() << '"' << " moved to position " << pos2 << endl;
		for (int i = 1; i < pos2; ++i) {
			temp2 = temp2->GetNext();
		}
		*head = temp1->GetNext();
		temp = temp2->GetNext();
		temp2->SetNext(temp1);
		temp1->SetNext(temp);
	}
	else {
		//find the 2 nodes
		for (int i = 1; i < pos1-1; ++i) {
			if (temp1->GetNext() == tail) 
				break;
			else
				temp1 = temp1->GetNext(); // temp1 = pos1-1
		}
		cout << '"' << temp1->GetNext()->GetSongName() << '"' << " moved to position " << pos2 << endl;
		//delete node 1 (check if node 1 is at the end)
		temp = temp1->GetNext();
		if (temp1->GetNext()->GetNext() == 0) {
			temp1->SetNext(0);
		}
		else {
			temp1->SetNext(temp->GetNext());
		}
		//temp stores floating node, 'insert' it at node 2 spot (check if node 2 is the head/tail)
		for (int i = 1; i < pos2 - 1; ++i) {
			if (temp2->GetNext() == tail)
				break;
			else
				temp2 = temp2->GetNext(); // temp2 = pos2-1
		}
		if (pos2 == 1) {
			temp->SetNext(*head);
			*head = temp;
		}
		else {
			temp2->InsertAfter(temp);
		}
	}
}

void PrintMenu(string title) {
	char c;
	bool cont = true;
	int i = 0;
	string id,song,artist;
	int length, pos1, pos2;
	PlaylistNode* headtemp;
	PlaylistNode* head = 0;
	PlaylistNode* tail = 0;
	while (cont) {
		cout << title << " PLAYLIST MENU" << endl << "a - Add song" << endl << "d - Remove song" << endl << "c - Change position of song" << endl << "s - Output songs by specific artist" << endl << "t - Output total time of playlist (in seconds)" << endl << "o - Output full playlist" << endl << "q - Quit" << endl << endl;
		cout << "Choose an option:" << endl;
		cin >> c;
		cin.ignore();
		switch (c) {
		case 'a':   			cout << "ADD SONG" << endl << "Enter song's unique ID:" << endl;
			getline(cin, id);
			cout << "Enter song's name:" << endl;
			getline(cin, song);
			cout << "Enter artist's name:" << endl;
			getline(cin, artist);
			cout << "Enter song's length (in seconds):" << endl;
			cin >> length;
			cout << endl;
			headtemp = new PlaylistNode(id,song,artist,length, 0);
			if (head == 0) {
				head = headtemp;
				tail = headtemp;
			}
			else {
				tail->SetNext(headtemp);
				tail = headtemp;
			}

			break;
		case 'd':
			cout << "REMOVE SONG" << endl << "Enter song's unique ID:" << endl;
			getline(cin, id);
			DeleteNode(&head,id);

			break;
		case 'c':
			cout << "CHANGE POSITION OF SONG" << endl << "Enter song's current position:" << endl;
			cin >> pos1;
			cout << "Enter new position for song:" << endl;
			cin >> pos2;
			ChangeNode(pos1, pos2, &head, tail);
			cout << endl;
			break;
		case 's':
			cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl << "Enter artist's name:" << endl;
			getline(cin, artist);
			i = 1;
			headtemp = head;
			while (headtemp != 0) {
				if (headtemp->GetArtistName() == artist) {
					cout << i << '.' << endl;
					headtemp->PrintPlaylistNode();
				}
				headtemp = headtemp->GetNext();
				i++;
			}
			cout << endl;
			break;
		case 't':
			i = 0;
			headtemp = head;
			while (headtemp != 0) {
				i = i + headtemp->GetSongLength();
				headtemp = headtemp->GetNext();
			}
			cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl << "Total time: " << i << " seconds" << endl << endl;
			break;
		case 'o':
			cout << title << " - OUTPUT FULL PLAYLIST" << endl;
			if (head == 0) {
				cout << "Playlist is empty" << endl << endl;
			}
			else {
				i = 1;
				PlaylistNode* ptr = head;
				while (ptr != 0) { 
					cout << i << '.' << endl;
					ptr->PrintPlaylistNode();
					ptr = ptr->GetNext();
					i++;
				}
			}
			break;
		case 'q':
			cont = false;
			break;
		default:
			break;
		}
	}
}

int main(){
    string temp;
    cout << "Enter playlist's title:" << endl;
	getline(cin, temp);
	cout << endl;
	PrintMenu(temp);

    return 0;
}
