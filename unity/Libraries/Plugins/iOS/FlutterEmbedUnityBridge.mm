#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// Flutter-Unity Communication Bridge for iOS
// Unity C# から呼び出される native 関数

extern "C" {
    // Flutter communication status
    static bool flutterInitialized = false;
    static NSMutableArray* messageQueue = nil;
    
    // Initialize Flutter communication
    void _initializeFlutterCommunication() {
        NSLog(@"[FlutterEmbedUnity] Initializing Flutter communication");
        flutterInitialized = true;
        
        // Initialize message queue
        if (messageQueue == nil) {
            messageQueue = [[NSMutableArray alloc] init];
        }
        
        // Send initialization notification
        [[NSNotificationCenter defaultCenter] postNotificationName:@"FlutterUnityInitialized" object:nil];
    }
    
    // Check if Flutter is ready
    bool _isFlutterReady() {
        return flutterInitialized;
    }
    
    // Send message to Flutter
    void _sendMessageToFlutter(const char* message) {
        if (message == NULL) {
            NSLog(@"[FlutterEmbedUnity] Error: Message is NULL");
            return;
        }
        
        NSString* messageString = [NSString stringWithUTF8String:message];
        NSLog(@"[FlutterEmbedUnity] Sending message to Flutter: %@", messageString);
        
        if (flutterInitialized) {
            // Send message through notification center
            NSDictionary* userInfo = @{@"message": messageString};
            [[NSNotificationCenter defaultCenter] postNotificationName:@"UnityMessageToFlutter" 
                                                                object:nil 
                                                              userInfo:userInfo];
        } else {
            // Queue message for later delivery
            if (messageQueue != nil) {
                [messageQueue addObject:messageString];
                NSLog(@"[FlutterEmbedUnity] Message queued (Flutter not ready): %@", messageString);
            }
        }
    }
    
    // Process queued messages when Flutter becomes ready
    void _processQueuedMessages() {
        if (messageQueue != nil && [messageQueue count] > 0) {
            NSLog(@"[FlutterEmbedUnity] Processing %lu queued messages", (unsigned long)[messageQueue count]);
            
            for (NSString* message in messageQueue) {
                NSDictionary* userInfo = @{@"message": message};
                [[NSNotificationCenter defaultCenter] postNotificationName:@"UnityMessageToFlutter" 
                                                                    object:nil 
                                                                  userInfo:userInfo];
            }
            
            [messageQueue removeAllObjects];
        }
    }
    
    // Get queued message count
    int _getQueuedMessageCount() {
        if (messageQueue != nil) {
            return (int)[messageQueue count];
        }
        return 0;
    }
}

// iOS App Controller Extension for Flutter communication
@interface FlutterEmbedUnityBridge : NSObject
+ (void)initializeBridge;
+ (void)handleFlutterReady;
@end

@implementation FlutterEmbedUnityBridge

+ (void)initializeBridge {
    NSLog(@"[FlutterEmbedUnity] Bridge initialized");
    
    // Listen for Flutter ready notifications
    [[NSNotificationCenter defaultCenter] addObserver:self 
                                             selector:@selector(handleFlutterReady) 
                                                 name:@"FlutterReady" 
                                               object:nil];
}

+ (void)handleFlutterReady {
    NSLog(@"[FlutterEmbedUnity] Flutter ready notification received");
    flutterInitialized = true;
    _processQueuedMessages();
}

@end