    /*

      MLT++ Player Example
      
      g++ simpleplayer.cxx -I/usr/include/mlt -I/usr/include/mlt++ -lmlt++ -lmlt -o simpleplayer

      Usage: simpleplayer <file>
      
      http://www.mltframework.org/twiki/bin/view/MLT/Framework
      
    */

    #include <iostream>
    #include <unistd.h>
    #include <Mlt.h>

    int main( int argc, char *argv[] )
    {
      Mlt::Profile *profile;
      Mlt::Repository *repository;
      Mlt::Consumer *consumer;
      Mlt::Producer *producer;
      
      // get default profile  
      profile= new Mlt::Profile("dv_pal_wide");
      
      // initialise the factory
      repository = Mlt::Factory::init();
      
      if (repository)
      {	
    	// Create the default consumer
    	consumer = new Mlt::Consumer( *profile,"sdl");

    	// Create via the default producer
    	producer = new Mlt::Producer( *profile,NULL, argv[ 1 ] );

    	// Connect the producer to the consumer
    	consumer->connect(*producer);

    	// Start the consumer
    	consumer->start();

    	// Wait for the consumer to terminate
    	while( !consumer->is_stopped() )
    	    sleep( 1 );

    	// Close the consumer
    	delete(consumer);

    	// Close the producer
    	delete(producer);

    	// Close the factory
    	Mlt::Factory::close();
        }
        else
        {
    	// Report an error during initialisation
    	std::cerr << "Unable to locate factory modules\n";
        }

        // End of program
        return 0;
    }
