// Auto-generated. Do not edit!

// (in-package motors.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class motorsCommand {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.deltaX = null;
      this.deltaY = null;
      this.faceArea = null;
      this.setnence = null;
    }
    else {
      if (initObj.hasOwnProperty('deltaX')) {
        this.deltaX = initObj.deltaX
      }
      else {
        this.deltaX = 0;
      }
      if (initObj.hasOwnProperty('deltaY')) {
        this.deltaY = initObj.deltaY
      }
      else {
        this.deltaY = 0;
      }
      if (initObj.hasOwnProperty('faceArea')) {
        this.faceArea = initObj.faceArea
      }
      else {
        this.faceArea = 0;
      }
      if (initObj.hasOwnProperty('setnence')) {
        this.setnence = initObj.setnence
      }
      else {
        this.setnence = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type motorsCommand
    // Serialize message field [deltaX]
    bufferOffset = _serializer.int32(obj.deltaX, buffer, bufferOffset);
    // Serialize message field [deltaY]
    bufferOffset = _serializer.int32(obj.deltaY, buffer, bufferOffset);
    // Serialize message field [faceArea]
    bufferOffset = _serializer.int32(obj.faceArea, buffer, bufferOffset);
    // Serialize message field [setnence]
    bufferOffset = _serializer.string(obj.setnence, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type motorsCommand
    let len;
    let data = new motorsCommand(null);
    // Deserialize message field [deltaX]
    data.deltaX = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [deltaY]
    data.deltaY = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [faceArea]
    data.faceArea = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [setnence]
    data.setnence = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.setnence.length;
    return length + 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'motors/motorsCommand';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c9eec707e4d0b5f449400290d53d427d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 deltaX
    int32 deltaY
    int32 faceArea
    string setnence
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new motorsCommand(null);
    if (msg.deltaX !== undefined) {
      resolved.deltaX = msg.deltaX;
    }
    else {
      resolved.deltaX = 0
    }

    if (msg.deltaY !== undefined) {
      resolved.deltaY = msg.deltaY;
    }
    else {
      resolved.deltaY = 0
    }

    if (msg.faceArea !== undefined) {
      resolved.faceArea = msg.faceArea;
    }
    else {
      resolved.faceArea = 0
    }

    if (msg.setnence !== undefined) {
      resolved.setnence = msg.setnence;
    }
    else {
      resolved.setnence = ''
    }

    return resolved;
    }
};

module.exports = motorsCommand;
