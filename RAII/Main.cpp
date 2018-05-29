#include "TemplateRAIIManager.h"
#include "ExampleData.h"

//#include "SpecialisedExampleClass.h"

#include <iostream>
#include <memory>

int main( ) {
	if( true ) {
		raii::RAIIManager<ExampleData> a = raii::make_unique_ptr<ExampleData>( );
		raii::RAIIManager<ExampleData> b = raii::make_unique_ptr<ExampleData>( 5.0f, 50.0f, 100.0f );
		raii::RAIIManager<ExampleData> c = raii::make_unique_ptr<ExampleData>( ExampleData( 5.0f, 50.0f, 100.0f ) );
		auto d = raii::make_unique_ptr<ExampleData>( );
		auto e = raii::make_unique_ptr<ExampleData>( 5.0f, 50.0f, 100.0f );
		auto f = raii::make_unique_ptr<ExampleData>( ExampleData( 5.0f, 50.0f, 100.0f ) );

		ExampleData tmp = ExampleData( 1.0f, 1.0f, 1.0f );
		auto g = raii::make_unique_ptr<ExampleData>( tmp );

		raii::RAIIManager<int> h = raii::make_unique_ptr<int>( 69 );

		std::printf( "%d", *h.get( ) );
	}
	return 0;
}