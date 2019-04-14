// Auto-generated. Do not edit!

// (in-package toi_bot_stt.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class speechTT {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.query = null;
      this.response = null;
      this.intent = null;
    }
    else {
      if (initObj.hasOwnProperty('query')) {
        this.query = initObj.query
      }
      else {
        this.query = '';
      }
      if (initObj.hasOwnProperty('response')) {
        this.response = initObj.response
      }
      else {
        this.response = '';
      }
      if (initObj.hasOwnProperty('intent')) {
        this.intent = initObj.intent
      }
      else {
        this.intent = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type speechTT
    // Serialize message field [query]
    bufferOffset = _serializer.string(obj.query, buffer, bufferOffset);
    // Serialize message field [response]
    bufferOffset = _serializer.string(obj.response, buffer, bufferOffset);
    // Serialize message field [intent]
    bufferOffset = _serializer.string(obj.intent, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type speechTT
    let len;
    let data = new speechTT(null);
    // Deserialize message field [query]
    data.query = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [response]
    data.response = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [intent]
    data.intent = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.query.length;
    length += object.response.length;
    length += object.intent.length;
    return length + 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'toi_bot_stt/speechTT';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c2e0321a6d60d7971f3d93f2eaf3408e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string query
    string response
    string intent
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new speechTT(null);
    if (msg.query !== undefined) {
      resolved.query = msg.query;
    }
    else {
      resolved.query = ''
    }

    if (msg.response !== undefined) {
      resolved.response = msg.response;
    }
    else {
      resolved.response = ''
    }

    if (msg.intent !== undefined) {
      resolved.intent = msg.intent;
    }
    else {
      resolved.intent = ''
    }

    return resolved;
    }
};

module.exports = speechTT;
