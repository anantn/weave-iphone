//
//  Service.h
//  Weave
//
//  Created by Anant Narayanan on 31/03/09.
//  Copyright 2009 Anant Narayanan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JSON/JSON.h>

#import "Verifier.h"
#import "Crypto.h"
#import "Connection.h"

@interface Service : NSObject <Responder> {
	id cb;
	NSString *server;
	NSString *baseURI;
	NSString *protocol;
	
	NSString *username;
	NSString *password;
	NSString *passphrase;
	
	NSData *iv;
	NSData *salt;
	NSData *public_key;
	NSData *private_key;
	
	Crypto *crypto;
	Connection *conn;
}

@property (nonatomic, copy) id cb;
@property (nonatomic, copy) NSString *server;
@property (nonatomic, copy) NSString *baseURI;
@property (nonatomic, copy) NSString *protocol;

@property (nonatomic, copy) NSData *iv;
@property (nonatomic, copy) NSData *salt;
@property (nonatomic, copy) NSData *public_key;
@property (nonatomic, copy) NSData *private_key;

@property (nonatomic, copy) NSString *username;
@property (nonatomic, copy) NSString *password;
@property (nonatomic, copy) NSString *passphrase;

@property (nonatomic, retain) Crypto *crypto;
@property (nonatomic, retain) Connection *conn;

-(Service *) initWithServer:(NSString *)server;

-(void) verifyWithUsername:(NSString *)user password:(NSString *)pwd passphrase:(NSString *)ph andCallback:(id <Verifier>)cb;
-(void) successWithString:(NSString *)response andIndex:(int)i;
-(void) failureWithError:(NSError *)error andIndex:(int)i;

-(void) setCluster;

@end