
#import <XCTest/XCTest.h>

#import <MapKit/MapKit.h>
#import <CoreLocation/CoreLocation.h>

// https://github.com/EvgenyKarkan/EKAlgorithms/blob/master/EKAlgorithms/NSArray%2BEKStuff.m
static inline NSArray *arrayShuffle(NSArray *array) {
    NSUInteger i = array.count;
    NSMutableArray *shuffledArray = [array mutableCopy];

    while (i) {
        NSUInteger randomIndex = arc4random_uniform((u_int32_t)i);
        [shuffledArray exchangeObjectAtIndex:randomIndex withObjectAtIndex:--i];
    }

    return [shuffledArray copy];
}


static inline double randomWithinRange(double min, double max) {
    return min + (max - min) * (double)arc4random_uniform(UINT32_MAX) / (UINT32_MAX - 1);
}


static inline BOOL CLLocationCoordinates2DEqual(CLLocationCoordinate2D coordinate, CLLocationCoordinate2D otherCoordinate) {
    static const double precision = 0.00000000001;

    return
    fabs(coordinate.latitude  - otherCoordinate.latitude)  < precision &&
    fabs(coordinate.longitude - otherCoordinate.longitude) < precision;
}

