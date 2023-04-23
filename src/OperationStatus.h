#if !defined(__OpserationStatus_H__)
#define __OperationStatus_H__

enum kmmOperationStatus {
    CommandWasPerformed = 0x00,
    CommandWasNotPerformed = 0x01,
    ItemDoesNotExist = 0x02,
    InvalidMessageId = 0x03,
    InvalidMac = 0x04,
    OutOfMemory = 0x05,
    CouldNotDecryptTheMessage = 0x06,
    InvalidMessageNumber = 0x07,
    InvalidKeyId = 0x08,
    InvalidAlgorithmId = 0x09,
    InvalidMfid = 0x0A,
    ModuleFailure = 0x0B,
    MiAllZeros = 0x0C,
    Keyfail = 0x0D,
    Unknown = 0xFF
};

#endif