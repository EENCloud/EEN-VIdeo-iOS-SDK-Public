//
//  RTSPSession.h
//  CMMobileSDK
//
//  Created by D. Ianchyk on 13/08/2018.
//  Copyright © 2018 Cameramanager. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    RTSPSessionStateInitialised,
    RTSPSessionStateSetupFinished,
    RTSPSessionStatePlaySent,
    RTSPSessionStatePlaying,
    RTSPSessionStatePauseSent,
    RTSPSessionStatePaused,
    RTSPSessionStateShuttingDown,
    RTSPSessionStateClosed,
} RTSPSessionState;

typedef enum {
    RTSPSessionAudioCodecALAW,
    RTSPSessionAudioCodecULAW,
    RTSPSessionAudioCodecAAC
} RTSPSessionAudioCodec;

@protocol RTSPSessionDelegate <NSObject>

- (void)onSessionStateChanged:(RTSPSessionState)state esn:(NSString *)esn;
- (void)onSessionFailedWithError:(NSString *)errorText esn:(NSString *)esn;
- (void)onSessionReceivedAudioData:(NSData *)data dts:(double)dts date:(NSDate *)date esn:(NSString *)esn audioCodec:(RTSPSessionAudioCodec)codec;
- (void)onSessionReceivedVideoData:(NSData *)data dts:(double)dts date:(NSDate *)date esn:(NSString *)esn;
- (void)onSessionReceivedSPS:(NSData *)spsData andPPS:(NSData*)ppsData esn:(NSString *)esn;

@end

@interface RTSPSession: NSObject // <AudioRecorderInterface>

@property (weak, nonatomic) id <RTSPSessionDelegate> delegate;

@property (readonly) RTSPSessionState state;

typedef void(^initialiseCompletionBlock)(BOOL status);

- (id)initWithURL:(NSURL *)url esn:(NSString *)esn;

- (void)initialise:(initialiseCompletionBlock)completed;
- (void)invalidate;

- (void)play;
- (void)pause;

@end
