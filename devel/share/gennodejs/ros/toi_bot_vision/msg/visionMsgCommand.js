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

class visionMsgCommand {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.visionStateCommand = null;
      this.personName = null;
    }
    else {
      if (initObj.hasOwnProperty('visionStateCommand')) {
        this.visionStateCommand = initObj.visionStateCommand
      }
      else {
        this.visionStateCommand = 0;
      }
      if (initObj.hasOwnProperty('personName')) {
        this.personName = initObj.personName
      }
      else {
        this.personName = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type visionMsgCommand
    // Serialize message field [visionStateCommand]
    bufferOffset = _serializer.int8(obj.visionStateCommand, buffer, bufferOffset);
    // Serialize message field [personName]
    bufferOffset = _serializer.string(obj.personName, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type visionMsgCommand
    let len;
    let data = new visionMsgCommand(null);
    // Deserialize message field [visionStateCommand]
    data.visionStateCommand = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [personName]
    data.personName = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.personName.length;
    return length + 5;
  }

  static datatype() {
    // Returns string type for a message object
    return 'toi_bot_vision/visionMsgCommand';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '69b80dd6addeec87f2c5298e187d1d3a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int8 visionStateCommand
    
    string personName
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new visionMsgCommand(null);
    if (msg.visionStateCommand !== undefined) {
      resolved.visionStateCommand = msg.visionStateCommand;
    }
    else {
      resolved.visionStateCommand = 0
    }

    if (msg.personName !== undefined) {
      resolved.personName = msg.personName;
    }
    else {
      resolved.personName = ''
    }

    return resolved;
    }
};

module.exports = visionMsgCommand;
