// Auto-generated. Do not edit!

// (in-package coordination_publisher.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class coordination {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.aX = null;
      this.aY = null;
      this.aZ = null;
    }
    else {
      if (initObj.hasOwnProperty('aX')) {
        this.aX = initObj.aX
      }
      else {
        this.aX = 0.0;
      }
      if (initObj.hasOwnProperty('aY')) {
        this.aY = initObj.aY
      }
      else {
        this.aY = 0.0;
      }
      if (initObj.hasOwnProperty('aZ')) {
        this.aZ = initObj.aZ
      }
      else {
        this.aZ = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type coordination
    // Serialize message field [aX]
    bufferOffset = _serializer.float32(obj.aX, buffer, bufferOffset);
    // Serialize message field [aY]
    bufferOffset = _serializer.float32(obj.aY, buffer, bufferOffset);
    // Serialize message field [aZ]
    bufferOffset = _serializer.float32(obj.aZ, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type coordination
    let len;
    let data = new coordination(null);
    // Deserialize message field [aX]
    data.aX = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [aY]
    data.aY = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [aZ]
    data.aZ = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'coordination_publisher/coordination';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e9ad96bdd5cf5d5e53c59d1a240ad03f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 aX
    float32 aY
    float32 aZ
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new coordination(null);
    if (msg.aX !== undefined) {
      resolved.aX = msg.aX;
    }
    else {
      resolved.aX = 0.0
    }

    if (msg.aY !== undefined) {
      resolved.aY = msg.aY;
    }
    else {
      resolved.aY = 0.0
    }

    if (msg.aZ !== undefined) {
      resolved.aZ = msg.aZ;
    }
    else {
      resolved.aZ = 0.0
    }

    return resolved;
    }
};

module.exports = coordination;
