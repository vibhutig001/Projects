express = require('express');
const eobj = express();
const port = 5555;
const { MongoClient } = require("mongodb");
const URL = "mongodb://localhost:27017";

const client = new MongoClient(URL);

async function GetConnection() {
    let result = await client.connect();
    let db = result.db("MarvellousInfosystems");
    return db.collection("Batch");
}

eobj.use((req, res, next) => {
    res.header("Access-Control-Allow-Origin", "http://localhost:4200");
    res.header("Access-Control-Allow-Headers", "Origin, X-Requested-with, Content-Type, Accept");
    next();
});

function Starter() {
    console.log("Marvellous server is in listening mode at : " + port);
}

eobj.listen(port, Starter);

function MarvellousGet(req, res) {
    res.send("Marvellous server started...");
}
eobj.get('/', MarvellousGet);
//////////////////////////////////////////////////////////////////////////////////////////////////
// Async function to handle batches
async function MarvellousBatches(req, res) {
    try {
        const batches = await ReadData();

        res.json(batches);
    } catch (error) {
        console.error("Error fetching batches:", error);
        res.status(500).json({ error: "Internal Server Error" });
    }
}
eobj.get('/getBatches', MarvellousBatches);

// Async function to read data
async function ReadData() {
    let data = await GetConnection();
    return await data.find().toArray();
}
/////////////////////////////////////////////////////////////////////////////////////////////////
async function InsertData() {
    let data = await GetConnection();
    let result = await data.insertOne({ "Name": "PPA", "Fees": "19520", "Duration": "4 Months" });

    if (result.acknowledged) {
        console.log("Data gets Inserted Successfully")
    }

}
eobj.get('/insertData', async(req, res) => {
    const insertionResult = await InsertData();
    res.json(insertionResult);
});
//////////////////////////////////////////////////////////////////////////////////////////////
async function DeleteData() {
    let data = await GetConnection();
    let result = await data.deleteOne({ "Name": "PPA" });
    if (result.acknowledged) {
        console.log("Data gets deleted Successfully")
    }
}
eobj.get('/DeleteData', async(req, res) => {
    const DeleteResult = await DeleteData();
    res.json(DeleteResult);
});
////////////////////////////////////////////////////////////////////////////////////////////
async function UpdateData() {
    let data = await GetConnection();
    let result = await data.updateOne({ "Name": "Python" }, { $set: { "Fees": "22000" } });
    if (result.acknowledged) {
        console.log("Data gets Updated Successfully")
    }
}
eobj.get('/UpdateData', async(req, res) => {
    const UpdateResult = await UpdateData();
    res.json(UpdateResult);
});
////////////////////////////////////////////////////////////////////////////////////////////
function main() {
    let ret;
    ret = GetConnection();
    console.log("Database Connected");
}

main();