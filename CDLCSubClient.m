// -*- mode: ObjC -*-

//  This file is part of class-dump, a utility for examining the Objective-C segment of Mach-O files.
//  Copyright (C) 1997-1998, 2000-2001, 2004-2011 Steve Nygard.

#import "CDLCSubClient.h"

@implementation CDLCSubClient

- (id)initWithDataCursor:(CDMachOFileDataCursor *)cursor;
{
    if ((self = [super initWithDataCursor:cursor])) {
        command.cmd = [cursor readInt32];
        command.cmdsize = [cursor readInt32];
        
        uint32_t strOffset = [cursor readInt32];
        NSParameterAssert(strOffset == 12);
        
        NSUInteger length = command.cmdsize - sizeof(command);
        //NSLog(@"expected length: %u", length);
        
        name = [[cursor readStringOfLength:length encoding:NSASCIIStringEncoding] retain];
        //NSLog(@"name: %@", name);
    }

    return self;
}

- (void)dealloc;
{
    [name release];

    [super dealloc];
}

#pragma mark -

- (uint32_t)cmd;
{
    return command.cmd;
}

- (uint32_t)cmdsize;
{
    return command.cmdsize;
}

@synthesize name;

@end
