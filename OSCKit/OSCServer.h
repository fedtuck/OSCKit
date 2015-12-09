#import <Foundation/Foundation.h>
#import <CocoaAsyncSocket/GCDAsyncUdpSocket.h>

#import "OSCMessage.h"

@protocol OSCServerDelegate <NSObject>

- (void)handleMessage:(OSCMessage*)message;
- (void)socketDidClose:(GCDAsyncUdpSocket *)sock withError:(NSError *)error;
- (void)socket:(GCDAsyncUdpSocket *)sock didConnectToAddress:(NSData *)address;
- (void)socket:(GCDAsyncUdpSocket *)sock didNotConnect:(NSError *)error;
@end

@interface OSCServer : NSObject <GCDAsyncUdpSocketDelegate>

@property (strong) id <OSCServerDelegate> delegate;

- (void)listen:(NSInteger)port;
- (void)stop;
- (BOOL)isConnected;
@end
