#include <iostream>
#include <vector>

using namespace std;

class Lift{
private: 
	int _bottomFloor;
	unsigned _topFloor;
	int _target;
	int _currentlyAt;

public:
	Lift(int bottom, unsigned top) {
		_bottomFloor = bottom;
		_topFloor = top;
		_target = 0;
		_currentlyAt = 0;
	}

	void FloorUp() {
		_currentlyAt = _currentlyAt++;
	}

	void FloorDown() {
		_currentlyAt = _currentlyAt--;
	}

	void MoveToFloor(int floor) {
		while (_currentlyAt != floor) {
			cout << "Hissi kerroksessa: " << _currentlyAt << endl;
			if (_currentlyAt < floor) {
				FloorUp();
			}
			if (_currentlyAt > floor) {
				FloorDown();
			}

			if (_currentlyAt == floor) {
				cout << "Olet saapunut kerrokseen " << _currentlyAt << "!\n";
			}

		if (floor == _currentlyAt) {

		}
		}
	}
};

class Building {
private:
	int _bottomFloor;
	unsigned _topFloor;
	vector<Lift> _lifts;

public:
	Building(int bottom, unsigned top) : _bottomFloor(bottom), _topFloor(top)
	{}

	void AddLifts(int howMany) {

		for (int i = 0; i < howMany; i++) {
			Lift liftAtHand = Lift(_bottomFloor, _topFloor);
			_lifts.push_back(liftAtHand);
		}
	}

	void MoveLift(int liftNr, int floor) {
		_lifts[liftNr - 1].MoveToFloor(floor);
	}

	void FireAlarm() {
			for (Lift& atHand : _lifts) {
				atHand.MoveToFloor(_bottomFloor);
			}
	}

};
//
//int main() {
//	Building build_a = Building(1, 7);
//	Building build_b = Building(0, 4);
//
//	build_a.AddLifts(2);
//	build_b.AddLifts(1);
//
//	build_a.MoveLift(2, 7);
//	build_b.MoveLift(1, 4);
//	build_a.FireAlarm();
//
//	return 0;
//}