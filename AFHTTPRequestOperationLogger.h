// AFHTTPRequestLogger.h
//
// Copyright (c) 2011 AFNetworking (http://afnetworking.com/)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, AFHTTPRequestLoggerLevel) {
  AFLoggerLevelOff,
  AFLoggerLevelDebug,
  AFLoggerLevelInfo,
  AFLoggerLevelWarn,
  AFLoggerLevelError,
  AFLoggerLevelFatal = AFLoggerLevelOff,
};

/**
 `AFHTTPRequestOperationLogger` logs requests and responses made by AFNetworking, with an adjustable level of detail.
 
 Applications should enable the shared instance of `AFHTTPRequestOperationLogger` in `AppDelegate -application:didFinishLaunchingWithOptions:`:

        [[AFHTTPRequestOperationLogger sharedLogger] startLogging];
 
 `AFHTTPRequestOperationLogger` listens for `AFNetworkingOperationDidStartNotification` and `AFNetworkingOperationDidFinishNotification` notifications, which are posted by AFNetworking as request operations are started and finish. For further customization of logging output, users are encouraged to implement desired functionality by listening for these notifications.
 */
@interface AFHTTPRequestOperationLogger : NSObject

- (id)initWithDDLogLevel:(int) ddLogLevel;

/**
 The level of logging detail. See "Logging Levels" for possible values. `AFLoggerLevelInfo` by default.
 */
@property (nonatomic, assign) AFHTTPRequestLoggerLevel level;

/**
 Only log operations conforming to the specified predicate, if specified. `nil` by default.
 */
@property (nonatomic, strong) NSPredicate *filterPredicate;

/**
 Returns the shared logger instance.
 */
+ (instancetype)sharedLoggerWithDDLogLevel:(int) logLevel;

/**
 Start logging requests and responses.
 */
- (void)startLogging;

/**
 Stop logging requests and responses.
 */
- (void)stopLogging;

@end

///----------------
/// @name Constants
///----------------

/**
 ## Logging Levels

 The following constants specify the available logging levels for `AFHTTPRequestOperationLogger`:

 enum {
 AFLoggerLevelOff,
 AFLoggerLevelDebug,
 AFLoggerLevelInfo,
 AFLoggerLevelWarn,
 AFLoggerLevelError,
 AFLoggerLevelFatal = AFLoggerLevelOff,
 }

 `AFLoggerLevelOff`
 Do not log requests or responses.

 `AFLoggerLevelDebug`
 Logs HTTP method, URL, header fields, & request body for requests, and status code, URL, header fields, response string, & elapsed time for responses.
 
 `AFLoggerLevelInfo`
 Logs HTTP method & URL for requests, and status code, URL, & elapsed time for responses.

 `AFLoggerLevelWarn`
 Logs HTTP method & URL for requests, and status code, URL, & elapsed time for responses, but only for failed requests.
 
 `AFLoggerLevelError`
 Equivalent to `AFLoggerLevelWarn`

 `AFLoggerLevelFatal`
 Equivalent to `AFLoggerLevelOff`
 */
