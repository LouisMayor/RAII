#pragma once

#include "ExampleData.h"
#include <iostream>

/*
	RAII class example.

	Pre C++11, once object leaves scope, the destructor will be called, with that deleting itself

	Post C++11, std::unique_ptr, etc, handles this automatically
*/

// Non-member allocation function
static ExampleData* CreateExampleDataObject( ) {
	ExampleData* tmp = new ExampleData;
	return tmp;
}

// synonmous with std::unique_ptr
class ExampleRAIIManager {
public:
	// RAII
	ExampleRAIIManager( ExampleData* _memory_handle ) {
		std::printf( "Data managed\n" );
		this->data = _memory_handle;
	};	
	~ExampleRAIIManager( ) {
		std::printf( "Data deleted\n" );
		if( data ) delete data;
	};
	
	// returns reference
	ExampleData& operator* ( ) {
		return *get( );
	}
	// returns reference to contained data
	ExampleData* operator-> () {
		return get( );
	}
	// returns reference to contained data
	ExampleData* get( ) {
		return data;
	}

	// Deletes owned object, can pass new data to replace
	void reset( ExampleData* _new_memory_handle = nullptr ) {
		if( _new_memory_handle != data ) {
			delete_self( );
		}
		data = _new_memory_handle;
		return;
	}
	// Releases "ownership" of memory, allowiing any object to take
	ExampleData* release( ) {
		ExampleData* tmp = get( );
		this->data = nullptr;
		return tmp;
	}

private:
	void delete_self( ) const {
		if( data ) {
			delete data;
		}
	}
	ExampleData* data;
};