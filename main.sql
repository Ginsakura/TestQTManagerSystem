/*
 Navicat Premium Data Transfer

 Source Server         : Manager
 Source Server Type    : SQLite
 Source Server Version : 3017000
 Source Schema         : main

 Target Server Type    : SQLite
 Target Server Version : 3017000
 File Encoding         : 65001

 Date: 09/05/2024 20:36:48
*/

PRAGMA foreign_keys = false;

-- ----------------------------
-- Table structure for Event
-- ----------------------------
DROP TABLE IF EXISTS "Event";
CREATE TABLE "Event" (
  "DateTime" datetime,
  "RoomNumber" int NOT NULL,
  "Event" text NOT NULL,
  "state" int,
  PRIMARY KEY ("DateTime")
);

-- ----------------------------
-- Table structure for Room
-- ----------------------------
DROP TABLE IF EXISTS "Room";
CREATE TABLE "Room" (
  "RoomNumber" int,
  "Price" int NOT NULL,
  "VIP" int,
  PRIMARY KEY ("RoomNumber")
);

-- ----------------------------
-- Table structure for RoomStatu
-- ----------------------------
DROP TABLE IF EXISTS "RoomStatu";
CREATE TABLE "RoomStatu" (
  "RoomNumber" int,
  "Reservation" bool,
  "ReservationDate" datetime,
  "CheckIn" bool,
  "CheckInDate" datetime,
  "CheckInTime" datetime,
  "PeopleNumber" int NOT NULL,
  "Remark" text,
  PRIMARY KEY ("RoomNumber")
);

-- ----------------------------
-- Table structure for Roomer
-- ----------------------------
DROP TABLE IF EXISTS "Roomer";
CREATE TABLE "Roomer" (
  "DateTime" datetime,
  "Name" text NOT NULL,
  "PersonID" text(18) NOT NULL,
  "Phone" text(11) NOT NULL,
  "Gender" bool NOT NULL,
  "RoomNumber" int NOT NULL,
  "UseVIP" bool,
  "State" int,
  PRIMARY KEY ("DateTime")
);

PRAGMA foreign_keys = true;
