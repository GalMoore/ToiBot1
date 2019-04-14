// Auto-generated. Do not edit!

// (in-package toi_bot_vision.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class visionMsgOutput {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.name = null;
      this.detectFace = null;
      this.deltaX = null;
      this.deltaY = null;
      this.canRecognize = null;
      this.emotion = null;
      this.faceArea = null;
    }
    else {
      if (initObj.hasOwnProperty('name')) {
        this.name = initObj.name
      }
      else {
        this.name = '';
      }
      if (initObj.hasOwnProperty('detectFace')) {
        this.detectFace = initObj.detectFace
      }
      else {
        this.detectFace = false;
      }
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
      if (initObj.hasOwnProperty('canRecognize')) {
        this.canRecognize = initObj.canRecognize
      }
      else {
        this.canRecognize = false;
      }
      if (initObj.hasOwnProperty('emotion')) {
        this.emotion = initObj.emotion
      }
      else {
        this.emotion = '';
      }
      if (initObj.hasOwnProperty('faceArea')) {
        this.faceArea = initObj.faceArea
      }
      else {
        this.faceArea = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type visionMsgOutput
    // Serialize message field [name]
    bufferOffset = _serializer.string(obj.name, buffer, bufferOffset);
    // Serialize message field [detectFace]
    bufferOffset = _serializer.bool(obj.detectFace, buffer, bufferOffset);
    // Serialize message field [deltaX]
    bufferOffset = _serializer.int32(obj.deltaX, buffer, bufferOffset);
    // Serialize message field [deltaY]
    bufferOffset = _serializer.int32(obj.deltaY, buffer, bufferOffset);
    // Serialize message field [canRecognize]
    bufferOffset = _serializer.bool(obj.canRecognize, buffer, bufferOffset);
    // Serialize message field [emotion]
    bufferOffset = _serializer.string(obj.emotion, buffer, bufferOffset);
    // Serialize message field [faceArea]
    bufferOffset = _serializer.int32(obj.faceArea, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type visionMsgOutput
    let len;
    let data = new visionMsgOutput(null);
    // Deserialize message field [name]
    data.name = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [detectFace]
    data.detectFace = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [deltaX]
    data.deltaX = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [deltaY]
    data.deltaY = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [canRecognize]
    data.canRecognize = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [emotion]
    data.emotion = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [faceArea]
    data.faceArea = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.name.length;
    length += object.emotion.length;
    return length + 22;
  }

  static datatype() {
    // Returns string type for a message object
    return 'toi_bot_vision/visionMsgOutput';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ffb96e74b49c6230c375e2b578de77a4';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    string name
    bool detectFace
    int32 deltaX
    int32 deltaY
    bool canRecognize
    string emotion
    int32 faceArea
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new visionMsgOutput(null);
    if (msg.name !== undefined) {
      resolved.name = msg.name;
    }
    else {
      resolved.name = ''
    }

    if (msg.detectFace !== undefined) {
      resolved.detectFace = msg.detectFace;
    }
    else {
      resolved.detectFace = false
    }

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

    if (msg.canRecognize !== undefined) {
      resolved.canRecognize = msg.canRecognize;
    }
    else {
      resolved.canRecognize = false
    }

    if (msg.emotion !== undefined) {
      resolved.emotion = msg.emotion;
    }
    else {
      resolved.emotion = ''
    }

    if (msg.faceArea !== undefined) {
      resolved.faceArea = msg.faceArea;
    }
    else {
      resolved.faceArea = 0
    }

    return resolved;
    }
};

module.exports = visionMsgOutput;
