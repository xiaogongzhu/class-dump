// -*- mode: ObjC -*-

//  This file is part of class-dump, a utility for examining the Objective-C segment of Mach-O files.
//  Copyright (C) 1997-1998, 2000-2001, 2004-2011 Steve Nygard.

#import <Foundation/Foundation.h>
#include <mach-o/loader.h>

@class CDDataCursor, CDMachOFile, CDLCSegment32;

@interface CDSection : NSObject
{
    NSString *segmentName;
    NSString *sectionName;

    NSData *data;
    struct {
        unsigned int hasLoadedData:1;
    } _flags;
}

- (id)init;

- (NSString *)description;

@property (retain) NSString *segmentName;
@property (retain) NSString *sectionName;

- (NSData *)data;
- (void)loadData;
- (void)unloadData;

@property (readonly) NSUInteger addr;
@property (readonly) NSUInteger size;

- (CDMachOFile *)machOFile;

- (BOOL)containsAddress:(NSUInteger)address;
- (NSUInteger)fileOffsetForAddress:(NSUInteger)address;

@end
