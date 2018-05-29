#pragma once

class ExampleData {
public:
	ExampleData( const float _x, const float _y, const float _z ) {
		x = _x;
		y = _y;
		z = _z;
	}
	ExampleData( const ExampleData&& _input ) {
		x = _input.x;
		y = _input.y; 
		z = _input.z;
	}
	ExampleData( const ExampleData& _input ) {
		x = _input.x;
		y = _input.y;
		z = _input.z;
	}
	ExampleData( ) {
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}
private:	
	ExampleData& operator=( const ExampleData& ) = delete;

	float x, y, z;
};