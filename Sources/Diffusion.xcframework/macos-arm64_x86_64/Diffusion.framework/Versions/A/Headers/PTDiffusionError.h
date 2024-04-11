//  Diffusion Client Library for iOS, tvOS and OS X / macOS
//
//  Copyright (c) 2017 - 2023 Push Technology Ltd., All Rights Reserved.
//
//  Use is subject to license terms.
//
//  NOTICE: All information contained herein is, and remains the
//  property of Push Technology. The intellectual and technical
//  concepts contained herein are proprietary to Push Technology and
//  may be covered by U.S. and Foreign Patents, patents in process, and
//  are protected by trade secret or copyright law.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Key used in the `userInfo` dictionary of an array of NSError objects, having
 the potential to convey more than one error encountered by an underlying
 implementation.

 The associated value is an array of one or more NSError objects.

 @since 6.0
 */
extern NSString *const PTDiffusionUnderlyingErrorsKey;


/**
 @file PTDiffusionError.h

 Collection of errors that can be raised by the Apple Client SDK.

 Errors with values from 100 to 501 originate from the Diffusion server.
 Remaining errors are unique to the Diffusion Apple Client SDK.

 @since 6.7
 */
typedef NS_ENUM(NSInteger, PTDiffusionError) {
    /**
     * Communication with the server failed.
     */
    PTDiffusionError_CommunicationFailure = 100,

    /**
     * Communication with the server failed because the session is closed.
     */
    PTDiffusionError_SessionClosed = 101,

    /**
     * Communication with the server failed due to a service request timeout.
     */
    PTDiffusionError_RequestTimeOut = 102,

    /**
     * The request was rejected because the used principal has insufficient permissions.
     */
    PTDiffusionError_AccessDenied = 103,

    /**
     * The request was rejected because the requested service is unsupported for this client.
     * @since 5.9
     */
    PTDiffusionError_Unsupported = 104,

    /**
     * An application callback threw an exception. Check logs for more information.
     * @since 5.9
     */
    PTDiffusionError_CallbackException = 105,

    /**
     * An operation failed because invalid data was received.
     * @since 6.0
     */
    PTDiffusionError_InvalidData = 106,

    /**
     * The session does not exist on the server.
     * @since 6.0
     */
    PTDiffusionError_NoSuchSession = 107,

    /**
     * A datatype operation has failed due to incompatibility.
     * @since 6.0
     */
    PTDiffusionError_IncompatibleDataType = 108,

    /**
     * A message was not handled by the server.
     * @since 6.0
     */
    PTDiffusionError_UnhandledMessage = 109,

    /**
     * The cluster was repartitioning and the request could not be routed.
     * @since 6.0
     */
    PTDiffusionError_ClusterRepartition = 110,

    /**
     * A topic update could not be performed because the topic is managed by a component which prohibits external updates.
     * @since 6.0
     */
    PTDiffusionError_IncompatibleState = 111,

    /**
     * The cluster operation could not be routed.
     * @since 6.0
     */
    PTDiffusionError_ClusterRouting = 112,

    /**
     * A conflicting registration exists on the same branch of the topic tree.
     * @since 6.5
     */
    PTDiffusionError_TopicTreeRegistrationConflict = 200,

    /**
     * A conflicting registration exists.
     */
    PTDiffusionError_HandlerConflict = 201,

    /**
     * An invalid path was supplied.
     */
    PTDiffusionError_InvalidPath = 202,

    /**
     * Incompatible update.
     */
    PTDiffusionError_IncompatibleUpdate = 500,

    /**
     * Topic update failed.
     */
    PTDiffusionError_UpdateFailed = 501,

    /**
     * No topic was found.
     */
    PTDiffusionError_NoSuchTopic = 9000,

    /**
     * Topic is not a time series topic.
     */
    PTDiffusionError_TopicIsNotTimeSeries = 9001,

    /**
     * No times series event was found.
     */
    PTDiffusionError_NoSuchEvent = 9002,

    /**
     * A request has been rejected.
     */
    PTDiffusionError_RejectedRequest = 9003,

    /**
     * A topic could not be added because one already exists with a different specification.
     */
    PTDiffusionError_TopicExistsMismatch = 9004,

    /**
     * A topic could not be added because an invalid path was specified.
     */
    PTDiffusionError_InvalidTopicPath = 9005,

    /**
     * A topic could not be added because an invalid specification was supplied.
     */
    PTDiffusionError_InvalidTopicSpecification = 9006,

    /**
     * A topic could not be added because the topic would breach a licensing limit.
     */
    PTDiffusionError_TopicLicenseLimit = 9007,

    /**
     * A topic could not be added because an incompatible topic already exists at the specified path.
     */
    PTDiffusionError_IncompatibleTopicExists = 9010,

    /**
     * An unexpected error occurred when creating a topic.
     */
    PTDiffusionError_UnexpectedTopicAddFailure = 9011,

    /**
     * The topic update failed because the constraint was not satisfied.
     */
    PTDiffusionError_UnsatisfiedConstraint = 9012,

    /**
     * The topic update failed because the update stream is no longer valid.
     */
    PTDiffusionError_InvalidUpdateStream = 9013,

    /**
     * Parsing the JSON patch failed.
     */
    PTDiffusionError_InvalidJsonPatch = 9014,

    /**
     * The JSON patch failed to apply. This happens when attempting to parse an illegal CBOR value.
     */
    PTDiffusionError_ApplyPatchFail = 9015,

    /**
     * A remote server with the specified name already exists.
     */
    PTDiffusionError_RemoteServerExists = 9016,

    /**
     * An invalid branch mapping was supplied.
     * @since 6.7
     */
    PTDiffusionError_InvalidBranchMappings = 9017,

    /**
     * Overflow occurred during a function.
     * @since 6.7
     */
    PTDiffusionError_Overflow = 20001,

    /**
     * Error while deserializing information.
     * @since 6.7
     */
    PTDiffusionError_DeserialisationError = 20002,

    /**
     * Unexpected class detected when setting session properties.
     * @since 6.7
     */
    PTDiffusionError_UnknownValueType = 20003,

    /**
     * Unexpected value detected when setting session properties.
     * @since 6.7
     */
    PTDiffusionError_UnexpectedValue = 20004,

    /**
     * Invalid session filter.
     * @since 6.7
     */
    PTDiffusionError_InvalidFilter = 20005,

    /**
     * Unexpected encoding detected while deserialising data.
     * @since 6.7
     */
    PTDiffusionError_UnknownEncoding = 20006,

    /**
     * Unexpected value detected for enumeration in question.
     * @since 6.7
     */
    PTDiffusionError_ValueNotInEnumeration = 20007,

    /**
     * Error while serialising message from the transport layer.
     * @since 6.7
     */
    PTDiffusionError_MessageSerialisationFailed = 20008,

    /**
     * JSON cannot be encoded as JSON string due to non-UTF8 characters.
     * @since 6.7
     */
    PTDiffusionError_StringWillNotEncodeToUTF8Losslessly = 20009,

    /**
     * Unable to read value as CBOR is empty.
     * @since 6.7
     */
    PTDiffusionError_EmptyCBOR = 20010,

    /**
     * Unhandled CBOR operation.
     * @since 6.7
     */
    PTDiffusionError_UnhandledCBOR = 20011,

    /**
     * Value has been read multiple times.
     * @since 6.7
     */
    PTDiffusionError_SetReadValueCalledMultipleTimes = 20012,

    /**
     * Unable to authenticate the principal, in the context of changing principal for the current session.
     * @since 6.7
     */
    PTDiffusionError_AuthenticationFailure = 20013,

    /**
     * An internal error occurred that prevented the session from creating the transport layer.
     * @since 6.7
     */
    PTDiffusionError_SessionFailedToCreateTransport = 20014,

    /**
     * Session has been closed by the transport layer.
     * @since 6.7
     */
    PTDiffusionError_SessionClosedByTransport = 20015,

    /**
     * Connection has been aborted by the reconnection strategy.
     * @since 6.7
     */
    PTDiffusionError_ConnectionAbortedByReconnectionStrategy = 20016,

    /**
     * Session has been closed due to inactivity.
     * @since 6.7
     */
    PTDiffusionError_SessionClosedDueToInactivity = 20017,

    /**
     * The received message type is not supported for routing.
     * @since 6.7
     */
    PTDiffusionError_MessageTypeNotSupportedForRouting = 20018,

    /**
     * Conversation ID was not found in the message headers.
     * @since 6.7
     */
    PTDiffusionError_MessageHeadersMissingFetchConversationId = 20019,

    /**
     * Reconnection has timed out.
     * @since 6.7
     */
    PTDiffusionError_ReconnectionTimeout = 20020,

    /**
     * Invalid string representation for session id.
     * @since 6.7
     */
    PTDiffusionError_SessionIdComponentCount = 20021,

    /**
     * Invalid string representation for session id.
     * @since 6.7
     */
    PTDiffusionError_SessionIdCharacterCount = 20022,

    /**
     * Invalid hex characters detected in session id.
     * @since 6.7
     */
    PTDiffusionError_SessionIdInvalidHexCharacters = 20023,

    /**
     * Invalid value detected for token in session id.
     * @since 6.7
     */
    PTDiffusionError_SessionIdScanHigh = 20024,

    /**
     * Invalid value detected for token in session id.
     * @since 6.7
     */
    PTDiffusionError_SessionIdScanLow = 20025,

    /**
     * Session lock has been cancelled.
     * @since 6.7
     */
    PTDiffusionError_SessionLockCancelled = 20026,

    /**
     * Incompatible datatypes.
     * @since 6.7
     */
    PTDiffusionError_DataTypeNotCompatible = 20027,

    /**
     * Unable to deserialize required information from stream.
     * @since 6.7
     */
    PTDiffusionError_StreamExhausted = 20028,

    /**
     * Failed to create topic view.
     * @since 6.7
     */
    PTDiffusionError_FailedToCreateTopicView = 20029,

    /**
     * CBOR functionality is not supported.
     * @since 6.7
     */
    PTDiffusionError_CBORNotSupported = 20030,

    /**
     * Unexpected item detected while parsing CBOR.
     * @since 6.7
     */
    PTDiffusionError_CBORUnexpectedItem = 20031,

    /**
     * Unable to append object as the container is immutable.
     * @since 6.7
     */
    PTDiffusionError_CBORImmutableContainer = 20032,

    /**
     * No instructions were parsed by the CBOR codec.
     * @since 6.7
     */
    PTDiffusionError_CBORMissingCodec = 20033,

    /**
     * Insufficient instructions were parsed by the CBOR codec.
     * @since 6.7
     */
    PTDiffusionError_CBORUnfinishedContainer = 20034,

    /**
     * Unable to append more objects as the document is already set.
     * @since 6.7
     */
    PTDiffusionError_CBORDocumentAlreadySet = 20035,

    /**
     * A map entry in the CBOR is incomplete.
     * @since 6.7
     */
    PTDiffusionError_CBORIncompleteMapEntry = 20036,

    /**
     * Unable to support 64-bit CBOR encoding in the current environment.
     * @since 6.7
     */
    PTDiffusionError_CBOR64BitUnsupportedOnThisRuntime = 20037,

    /**
     * Value is out of range.
     * @since 6.7
     */
    PTDiffusionError_OutOfRange = 20038,

    /**
     * Provided additional information was unhandled.
     * @since 6.7
     */
    PTDiffusionError_CBORUnhandledInfoValue = 20039,

    /**
     * Unable to parse string due to non-UTF8 characters.
     * @since 6.7
     */
    PTDiffusionError_CBORInvalidUTF8 = 20040,

    /**
     * Parsing of a particular type is unhandled.
     * @since 6.7
     */
    PTDiffusionError_CBORParsingUnhandledType = 20041,

    /**
     * Unable to serialize a type using CBOR codec.
     * @since 6.7
     */
    PTDiffusionError_CBORSerialisationUnhandledType = 20042,

    /**
     * Unable to serialize a class using CBOR codec.
     * @since 6.7
     */
    PTDiffusionError_CBORSerialisationUnhandledClass = 20043,

    /**
     * Maximum recursion depth reached while running CBOR serialisation.
     * @since 6.7
     */
    PTDiffusionError_CBORSerialisationMaximumRecursionDepthExceeded = 20044,

    /**
     * Unexpected item detected while parsing the binary delta.
     * @since 6.7
     */
    PTDiffusionError_BinaryDeltaUnexpectedItem = 20045,

    /**
     * Unsupported item for the purposes of binary delta parsing.
     * @since 6.7
     */
    PTDiffusionError_BinaryDeltaUnsupportedItem = 20046,

    /**
     * Binary delta parsing is expecting the size of the copy.
     * @since 6.7
     */
    PTDiffusionError_BinaryDeltaPendingCopyLength = 20047,

    /**
     * Binary delta parsing is expecting a break.
     * @since 6.7
     */
    PTDiffusionError_BinaryDeltaPendingBreak = 20048,

    /**
     * Value is out of range for the current runtime environment.
     * @since 6.7
     */
    PTDiffusionError_BinaryDeltaOutOfRangeForRuntime = 20049,

    /**
     * Delegate was not found.
     * @since 6.7
     */
    PTDiffusionError_DelegateNotFound = 20050,

    /**
     * Multiple topic constraints found.
     * @since 6.7
     */
    PTDiffusionError_MultipleTopicConstraintsFound = 20051,

    /**
     * Insufficient data for complete deserialisation.
     * @since 6.7
     */
    PTDiffusionError_ConnectionResponseInsufficientData = 20052,

    /**
     * Unknown value detected for a given field.
     * @since 6.7
     */
    PTDiffusionError_ConnectionResponseUnknownValue = 20053,

    /**
     * The service is in an invalid state.
     * @since 6.7
     */
    PTDiffusionError_InvalidState = 20054,

    /**
     * Topic cache does not have enough information to resolve the received delta.
     * @since 6.7
     */
    PTDiffusionError_NoOldValueToApplyDeltaTo = 20055,

    /**
     * Topic cache does not have enough information to resolve the received delta type.
     * @since 6.7
     */
    PTDiffusionError_NoDeltaTypeAvailable = 20056,

    /**
     * Encoding of message headers to string failed.
     * @since 6.7
     */
    PTDiffusionError_MessageHeadersToStringEncodingFailed = 20057,

    /**
     * Unknown message type.
     * @since 6.7
     */
    PTDiffusionError_UnknownMessageType = 20058,

    /**
     * Update Stream has an invalid value set for its datatype.
     * @since 6.7
     */
    PTDiffusionError_UpdateStreamInvalidNilValue = 20059,

    /**
     * Unable to convert received class into expected class.
     * @since 6.7
     */
    PTDiffusionError_UnsupportedValueClass = 20060,

    /**
     * Unexpected type received.
     * @since 6.7
     */
    PTDiffusionError_UnhandledTypeReceived = 20061,

    /**
     * Unexpected string start detected.
     * @since 6.7
     */
    PTDiffusionError_UnexpectedStringStart = 20062,

    /**
     * Unexpected break detected.
     * @since 6.7
     */
    PTDiffusionError_UnexpectedBreak = 20063,

    /**
     * Unknown datatype for received name.
     * @since 6.7
     */
    PTDiffusionError_UnknownDataTypeName = 20064,

    /**
     * Received topic data which contradicts the topic cache.
     * @since 6.7
     */
    PTDiffusionError_DataLossTopicPathNotInCache = 20065,

    /**
     * Topic path is already present in the topic cache.
     * @since 6.7
     */
    PTDiffusionError_InvalidSequenceOnCheckByPath = 20066,

    /**
     * Topic id is already present in the topic cache.
     * @since 6.7
     */
    PTDiffusionError_InvalidSequenceOnCheckById = 20067,

    /**
     * Unable to generate notifier from stream.
     * @since 6.7
     */
    PTDiffusionError_UnableToGenerateNotifier = 20068,

    /**
     * Stream registry is closed.
     * @since 6.7
     */
    PTDiffusionError_StreamRegistryClosed = 20069,

    /**
     * Buffered data reader has been requested while transport layer is in an invalid state.
     * @since 6.7
     */
    PTDiffusionError_BufferedDataReaderRequestInvalidState = 20070,

    /**
     * Connection response received while transport layer is in an invalid state.
     * @since 6.7
     */
    PTDiffusionError_ConnectionResponseInvalidState = 20071,

    /**
     * Message received while transport layer is in an invalid state.
     * @since 6.7
     */
    PTDiffusionError_MessageReceivedInvalidState = 20072,

    /**
     * Error occurred for unknown reason.
     * @since 6.7
     */
    PTDiffusionError_UnknownReason = 20073,

    /**
     * Error occurred while appending data to the HTTP message.
     * @since 6.7
     */
    PTDiffusionError_HTTPMessageAppendDataError = 20074,

    /**
     * Invalid status code received.
     * @since 6.7
     */
    PTDiffusionError_InvalidStatusCode = 20075,

    /**
     * Authentication challenge handler is not set.
     * @since 6.7
     */
    PTDiffusionError_MissingAuthenticationChallengeHandler = 20076,

    /**
     * Maximum number of conversations has been reached.
     * @since 6.7
     */
    PTDiffusionError_MaximumConversationsReached = 20077,

    /**
     * Invalid start of a JSON pointer expression.
     * @since 6.7
     */
    PTDiffusionError_JsonPointerExpressionInvalidStart = 20078,

    /**
     * Failed to write to stream.
     * @since 6.7
     */
    PTDiffusionError_FailedWriteToStream = 20079,

    /**
     * Unknown stream error.
     * @since 6.7
     */
    PTDiffusionError_UnknownStreamError = 20080,

    /**
     * Failed to verify SSL.
     * @since 6.7
     */
    PTDiffusionError_FailedToVerifySSL = 20081,

    /**
     * Maximum message queue exceeded when writing to stream.
     * @since 6.7
     */
    PTDiffusionError_WriteFailedMaxQueueSize = 20082,

    /**
     * Failed to write to stream of fixed size or reached capacity.
     * @since 6.7
     */
    PTDiffusionError_WriteFailedFixedSize = 20083,

    /**
     * Failed to enable SSL.
     * @since 6.7
     */
    PTDiffusionError_FailedToEnableSSL = 20084,

    /**
     * Failed to configure SSL.
     * @since 6.7
     */
    PTDiffusionError_FailedToConfigureSSL = 20085,

    /**
     * Connection timeout.
     * @since 6.7
     */
    PTDiffusionError_ConnectionTimeout = 20086,

    /**
     * Unexpected HTTP response code.
     * @since 6.7
     */
    PTDiffusionError_UnexpectedHttpResponseCode = 20087,

    /**
     * Unexpected HTTP response header value.
     * @since 6.7
     */
    PTDiffusionError_UnexpectedHttpResponseHeaderValue = 20088,

    /**
     * Unexpected frame operation code.
     * @since 6.7
     */
    PTDiffusionError_UnexpectedFrameOperationCode = 20089,

    /**
     * Maximum payload length exceeded.
     * @since 6.7
     */
    PTDiffusionError_MaximumPayloadLengthExceeded = 20090,

    /**
     * Connection is closed.
     * @since 6.7
     */
    PTDiffusionError_ConnectionClosed = 20091,

    /**
     * Invalid frame start.
     * @since 6.7
     */
    PTDiffusionError_InvalidFrameStart = 20092,

    /**
     * Payload data is masked.
     * @since 6.7
     */
    PTDiffusionError_MaskedPayloadData = 20093,

    /**
     * Unable to support 64-bit encoding in the current environment.
     * @since 6.7
     */
    PTDiffusionError_64BitNotSupportedForRuntime = 20094,

    /**
     * Failed to initialize compression stream.
     * @since 6.7
     */
    PTDiffusionError_ZlibInitFailed = 20095,

    /**
     * Failed to process compression.
     * @since 6.7
     */
    PTDiffusionError_ZlibProcessFailed = 20096,

    /**
     * Failed to destroy compression stream.
     * @since 6.7
     */
    PTDiffusionError_ZlibDestroyFailed = 20097,

    /**
     * Compressed data is too small.
     * @since 6.7
     */
    PTDiffusionError_ZlibCompressedDataTooSmall = 20098,

    /**
     * Compressed data header is incorrect.
     * @since 6.7
     */
    PTDiffusionError_ZlibCompressedDataHeaderIncorrect = 20099,

    /**
     * Last record is not variable.
     * @since 6.7
     */
    PTDiffusionError_LastRecordIsNotVariable = 20100,

    /**
     * Last record has reached maximum occurrences.
     * @since 6.7
     */
    PTDiffusionError_LastRecordHasReachedMaximumOccurrences = 20101,

    /**
     * Last record has no occurrences to add field to.
     * @since 6.7
     */
    PTDiffusionError_LastRecordHasNoOccurrencesToAddFieldTo = 20102,

    /**
     * Last field is not variable.
     * @since 6.7
     */
    PTDiffusionError_LastFieldIsNotVariable = 20103,

    /**
     * Adding values would exceed maximum field occurrences.
     * @since 6.7
     */
    PTDiffusionError_AddingValuesWouldExceedMaximumFieldOccurrences = 20104,

    /**
     * Removal would violate the minimum number of occurrences.
     * @since 6.7
     */
    PTDiffusionError_RemovalWouldViolateTheMinimumNumberOfOccurrences = 20105,

    /**
     * Formatter failed to generate field.
     * @since 6.7
     */
    PTDiffusionError_FormatterFailedToGenerate = 20106,

    /**
     * String contains invalid characters.
     * @since 6.7
     */
    PTDiffusionError_InvalidCharactersInString = 20107,

    /**
     * Operation has resulted in an error.
     * @since 6.7
     */
    PTDiffusionError_OperationError = 20108,

    /**
     * String cannot be encoded due to non-UTF8 characters.
     * @since 6.7
     */
    PTDiffusionError_EncodeFromUTF8Error = 20109,

    /**
     * Data cannot be decoded into string due to non-UTF8 characters.
     * @since 6.7
     */
    PTDiffusionError_DecodeToUTF8Error = 20110,

    /**
     * Field key's name is missing.
     * @since 6.7
     */
    PTDiffusionError_RecordSchemaFieldKeyMissingName = 20111,

    /**
     * Field key is missing a closing bracket.
     * @since 6.7
     */
    PTDiffusionError_RecordSchemaFieldKeyMissingClosingBracket = 20112,

    /**
     * Characters found after closing bracket.
     * @since 6.7
     */
    PTDiffusionError_RecordSchemaFieldKeyCharactersFoundAfterClosingBracket = 20113,

    /**
     * Index in key could not be parsed.
     * @since 6.7
     */
    PTDiffusionError_RecordSchemaFieldKeyIndexCouldNotBeParsed = 20114,

    /**
     * The key has too many parts.
     * @since 6.7
     */
    PTDiffusionError_RecordSchemaFieldKeyTooManyKeyParts = 20115,

    /**
     * The total number of records is less than the minimum required.
     * @since 6.7
     */
    PTDiffusionError_InsufficientRecords = 20116,

    /**
     * The total number of records exceeds the maximum allowed.
     * @since 6.7
     */
    PTDiffusionError_TooManyRecords = 20117,

    /**
     * The total number of fields is less than the minimum required.
     * @since 6.7
     */
    PTDiffusionError_InsufficientFields = 20118,

    /**
     * The model size exceeds the maximum size.
     * @since 6.7
     */
    PTDiffusionError_RecordModelTooBig = 20119,

    /**
     * The record size exceeds the maximum size.
     * @since 6.7
     */
    PTDiffusionError_RecordTooBig = 20120,

    /**
     * The total number of fields exceeds the maximum allowed.
     * @since 6.7
     */
    PTDiffusionError_TooManyFields = 20121,

    /**
     * The record size exceeds the maximum size.
     * @since 6.7
     */
    PTDiffusionError_ResolvedRecordIndexExceedsModelSize = 20122,

    /**
     * The total number of fields exceeds the maximum allowed.
     * @since 6.7
     */
    PTDiffusionError_ResolvedFieldIndexExceedsModelSize = 20123,

    /**
     * Root of the JSON is not a dictionary.
     * @since 6.7
     */
    PTDiffusionError_RecordSchemaRootIsNotObject = 20124,

    /**
     * Value in JSON is not a string.
     * @since 6.7
     */
    PTDiffusionError_RecordSchemaNameIsNotString = 20125,

    /**
     * Value in JSON is not a dictionary.
     * @since 6.7
     */
    PTDiffusionError_RecordSchemaValueIsNotObject = 20126,

    /**
     * Value in JSON is not a number.
     * @since 6.7
     */
    PTDiffusionError_RecordSchemaValueIsNotNumber = 20127,

    /**
     * Record has no fields.
     * @since 6.7
     */
    PTDiffusionError_RecordSchemaRecordHasNoFields = 20128,

    /**
     * Value in JSON is not an array.
     * @since 6.7
     */
    PTDiffusionError_RecordSchemaValueIsNotArray = 20129,

    /**
     * Records not found.
     * @since 6.7
     */
    PTDiffusionError_RecordSchemaFieldRecordsNotDefined = 20130,

    /**
     * Cannot find field with given name.
     * @since 6.7
     */
    PTDiffusionError_RecordSchemaCannotFindField = 20131,

    /**
     * Record name is not defined.
     * @since 6.7
     */
    PTDiffusionError_RecordSchemaRecordNameNotDefined = 20132,

    /**
     * Field name is not defined.
     * @since 6.7
     */
    PTDiffusionError_RecordSchemaFieldNameNotDefined = 20133,

    /**
     * Key is not a string.
     * @since 6.7
     */
    PTDiffusionError_RecordSchemaKeyIsNotString = 20134,

    /**
     * Unknown key.
     * @since 6.7
     */
    PTDiffusionError_RecordSchemaUnknownKey = 20135,

    /**
     * Record not found.
     * @since 6.7
     */
    PTDiffusionError_RecordSchemaUnknownRecordName = 20136,

    /**
     * Need to add a record before adding the fields.
     * @since 6.7
     */
    PTDiffusionError_RecordBuilderNoCurrentRecord = 20137,

    /**
     * Field already exists with the same name.
     * @since 6.7
     */
    PTDiffusionError_RecordBuilderDuplicateFieldName = 20138,

    /**
     * Cannot add a field after a variable multiplicity field.
     * @since 6.7
     */
    PTDiffusionError_RecordBuilderFieldAfterVariableMultiplicityField = 20139,

    /**
     * There are no fields for the current record.
     * @since 6.7
     */
    PTDiffusionError_RecordBuilderEmptyFields = 20140,

    /**
     * Records are empty.
     * @since 6.7
     */
    PTDiffusionError_RecordBuilderEmptyRecords = 20141,

    /**
     * Record already exists with the same name.
     */
    PTDiffusionError_RecordBuilderDuplicateRecordName = 20142,

    /**
     * The scale is not positive.
     * @since 6.7
     */
    PTDiffusionError_RecordSchemaScaleNotPositive = 20143,

    /**
     * Field is negative.
     * @since 6.7
     */
    PTDiffusionError_RecordSchemaNegativeField = 20144,

    /**
     * Field is invalid.
     * @since 6.7
     */
    PTDiffusionError_RecordSchemaInvalidField = 20145,

    /**
     * The string supplied has been encoded incorrectly.
     * @since 6.2
     */
    PTDiffusionError_MisquotedInput = 20146,

    /**
     * The filter was rejected. The message was not sent to any clients.
     * @since 6.5
     */
    PTDiffusionError_SendToFilterRejected = 20147,

    /**
     * The session was closed after being unexpectedly disconnected.
     * @since 6.0
     */
    PTDiffusionError_Disconnected = 20148,

    /**
     * The session was closed locally.
     * @since 6.0
     */
    PTDiffusionError_ClosedByClient = 20149,

    /**
     * There was a problem when establishing a session. The session is closed. No further operations are possible.
     * @since 6.0
     */
    PTDiffusionError_Establishment = 20150,

    /**
     * The session operation failed due to a security constraint. Repeating the operation with the same security credentials is likely to fail.
     * @since 6.0
     */
    PTDiffusionError_Security = 20151,

    /**
     * The session operation failed due to an unrecognized response code.
     * @since 6.3
     */
    PTDiffusionError_UnrecognizedResponseCode = 20152,

    /**
     * The session was closed remotely.
     * @since 6.6
     */
    PTDiffusionError_ClosedByServer = 20153,

    /**
     * Server unexpectedly aborted.
     * @since 6.0
     */
    PTDiffusionError_ServerAborted = 20154,

    /**
     * Dictionary does not contain requested key.
     * @since 6.7
     */
    PTDiffusionError_KeyNotFoundInDictionary = 20155,

    /**
     * Invalid Protocol Version.
     * @since 6.8
     */
    PTDiffusionError_ClientVersionDowngrade = 20157,
    
    /**
     * Invalid argument for the method.
     * @since 6.8
     */
    PTDiffusionError_InvalidArgument = 20160,

};

NS_ASSUME_NONNULL_END
