; Auto-generated. Do not edit!


(cl:in-package toi_bot_vision-msg)


;//! \htmlinclude visionMsgOutput.msg.html

(cl:defclass <visionMsgOutput> (roslisp-msg-protocol:ros-message)
  ((name
    :reader name
    :initarg :name
    :type cl:string
    :initform "")
   (detectFace
    :reader detectFace
    :initarg :detectFace
    :type cl:boolean
    :initform cl:nil)
   (deltaX
    :reader deltaX
    :initarg :deltaX
    :type cl:integer
    :initform 0)
   (deltaY
    :reader deltaY
    :initarg :deltaY
    :type cl:integer
    :initform 0)
   (canRecognize
    :reader canRecognize
    :initarg :canRecognize
    :type cl:boolean
    :initform cl:nil)
   (emotion
    :reader emotion
    :initarg :emotion
    :type cl:string
    :initform "")
   (faceArea
    :reader faceArea
    :initarg :faceArea
    :type cl:integer
    :initform 0))
)

(cl:defclass visionMsgOutput (<visionMsgOutput>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <visionMsgOutput>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'visionMsgOutput)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name toi_bot_vision-msg:<visionMsgOutput> is deprecated: use toi_bot_vision-msg:visionMsgOutput instead.")))

(cl:ensure-generic-function 'name-val :lambda-list '(m))
(cl:defmethod name-val ((m <visionMsgOutput>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader toi_bot_vision-msg:name-val is deprecated.  Use toi_bot_vision-msg:name instead.")
  (name m))

(cl:ensure-generic-function 'detectFace-val :lambda-list '(m))
(cl:defmethod detectFace-val ((m <visionMsgOutput>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader toi_bot_vision-msg:detectFace-val is deprecated.  Use toi_bot_vision-msg:detectFace instead.")
  (detectFace m))

(cl:ensure-generic-function 'deltaX-val :lambda-list '(m))
(cl:defmethod deltaX-val ((m <visionMsgOutput>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader toi_bot_vision-msg:deltaX-val is deprecated.  Use toi_bot_vision-msg:deltaX instead.")
  (deltaX m))

(cl:ensure-generic-function 'deltaY-val :lambda-list '(m))
(cl:defmethod deltaY-val ((m <visionMsgOutput>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader toi_bot_vision-msg:deltaY-val is deprecated.  Use toi_bot_vision-msg:deltaY instead.")
  (deltaY m))

(cl:ensure-generic-function 'canRecognize-val :lambda-list '(m))
(cl:defmethod canRecognize-val ((m <visionMsgOutput>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader toi_bot_vision-msg:canRecognize-val is deprecated.  Use toi_bot_vision-msg:canRecognize instead.")
  (canRecognize m))

(cl:ensure-generic-function 'emotion-val :lambda-list '(m))
(cl:defmethod emotion-val ((m <visionMsgOutput>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader toi_bot_vision-msg:emotion-val is deprecated.  Use toi_bot_vision-msg:emotion instead.")
  (emotion m))

(cl:ensure-generic-function 'faceArea-val :lambda-list '(m))
(cl:defmethod faceArea-val ((m <visionMsgOutput>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader toi_bot_vision-msg:faceArea-val is deprecated.  Use toi_bot_vision-msg:faceArea instead.")
  (faceArea m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <visionMsgOutput>) ostream)
  "Serializes a message object of type '<visionMsgOutput>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'name))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'detectFace) 1 0)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'deltaX)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'deltaY)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'canRecognize) 1 0)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'emotion))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'emotion))
  (cl:let* ((signed (cl:slot-value msg 'faceArea)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <visionMsgOutput>) istream)
  "Deserializes a message object of type '<visionMsgOutput>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:slot-value msg 'detectFace) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'deltaX) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'deltaY) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:setf (cl:slot-value msg 'canRecognize) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'emotion) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'emotion) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'faceArea) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<visionMsgOutput>)))
  "Returns string type for a message object of type '<visionMsgOutput>"
  "toi_bot_vision/visionMsgOutput")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'visionMsgOutput)))
  "Returns string type for a message object of type 'visionMsgOutput"
  "toi_bot_vision/visionMsgOutput")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<visionMsgOutput>)))
  "Returns md5sum for a message object of type '<visionMsgOutput>"
  "ffb96e74b49c6230c375e2b578de77a4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'visionMsgOutput)))
  "Returns md5sum for a message object of type 'visionMsgOutput"
  "ffb96e74b49c6230c375e2b578de77a4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<visionMsgOutput>)))
  "Returns full string definition for message of type '<visionMsgOutput>"
  (cl:format cl:nil "~%string name~%bool detectFace~%int32 deltaX~%int32 deltaY~%bool canRecognize~%string emotion~%int32 faceArea~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'visionMsgOutput)))
  "Returns full string definition for message of type 'visionMsgOutput"
  (cl:format cl:nil "~%string name~%bool detectFace~%int32 deltaX~%int32 deltaY~%bool canRecognize~%string emotion~%int32 faceArea~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <visionMsgOutput>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'name))
     1
     4
     4
     1
     4 (cl:length (cl:slot-value msg 'emotion))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <visionMsgOutput>))
  "Converts a ROS message object to a list"
  (cl:list 'visionMsgOutput
    (cl:cons ':name (name msg))
    (cl:cons ':detectFace (detectFace msg))
    (cl:cons ':deltaX (deltaX msg))
    (cl:cons ':deltaY (deltaY msg))
    (cl:cons ':canRecognize (canRecognize msg))
    (cl:cons ':emotion (emotion msg))
    (cl:cons ':faceArea (faceArea msg))
))
