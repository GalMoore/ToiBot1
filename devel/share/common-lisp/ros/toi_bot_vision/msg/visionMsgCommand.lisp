; Auto-generated. Do not edit!


(cl:in-package toi_bot_vision-msg)


;//! \htmlinclude visionMsgCommand.msg.html

(cl:defclass <visionMsgCommand> (roslisp-msg-protocol:ros-message)
  ((visionStateCommand
    :reader visionStateCommand
    :initarg :visionStateCommand
    :type cl:fixnum
    :initform 0)
   (personName
    :reader personName
    :initarg :personName
    :type cl:string
    :initform ""))
)

(cl:defclass visionMsgCommand (<visionMsgCommand>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <visionMsgCommand>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'visionMsgCommand)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name toi_bot_vision-msg:<visionMsgCommand> is deprecated: use toi_bot_vision-msg:visionMsgCommand instead.")))

(cl:ensure-generic-function 'visionStateCommand-val :lambda-list '(m))
(cl:defmethod visionStateCommand-val ((m <visionMsgCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader toi_bot_vision-msg:visionStateCommand-val is deprecated.  Use toi_bot_vision-msg:visionStateCommand instead.")
  (visionStateCommand m))

(cl:ensure-generic-function 'personName-val :lambda-list '(m))
(cl:defmethod personName-val ((m <visionMsgCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader toi_bot_vision-msg:personName-val is deprecated.  Use toi_bot_vision-msg:personName instead.")
  (personName m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <visionMsgCommand>) ostream)
  "Serializes a message object of type '<visionMsgCommand>"
  (cl:let* ((signed (cl:slot-value msg 'visionStateCommand)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'personName))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'personName))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <visionMsgCommand>) istream)
  "Deserializes a message object of type '<visionMsgCommand>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'visionStateCommand) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'personName) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'personName) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<visionMsgCommand>)))
  "Returns string type for a message object of type '<visionMsgCommand>"
  "toi_bot_vision/visionMsgCommand")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'visionMsgCommand)))
  "Returns string type for a message object of type 'visionMsgCommand"
  "toi_bot_vision/visionMsgCommand")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<visionMsgCommand>)))
  "Returns md5sum for a message object of type '<visionMsgCommand>"
  "69b80dd6addeec87f2c5298e187d1d3a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'visionMsgCommand)))
  "Returns md5sum for a message object of type 'visionMsgCommand"
  "69b80dd6addeec87f2c5298e187d1d3a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<visionMsgCommand>)))
  "Returns full string definition for message of type '<visionMsgCommand>"
  (cl:format cl:nil "int8 visionStateCommand~%~%string personName~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'visionMsgCommand)))
  "Returns full string definition for message of type 'visionMsgCommand"
  (cl:format cl:nil "int8 visionStateCommand~%~%string personName~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <visionMsgCommand>))
  (cl:+ 0
     1
     4 (cl:length (cl:slot-value msg 'personName))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <visionMsgCommand>))
  "Converts a ROS message object to a list"
  (cl:list 'visionMsgCommand
    (cl:cons ':visionStateCommand (visionStateCommand msg))
    (cl:cons ':personName (personName msg))
))
