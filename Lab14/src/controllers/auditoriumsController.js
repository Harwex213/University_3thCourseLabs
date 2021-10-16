const express = require("express");
const table = require("../services/tablesDto").auditoriumsService;
const crudController = require("./crudController")

const getAuditoriums = (request, response, next) => {
    next({ table });
};

const postAuditorium = async (request, response, next) => {
    const body = request.body;
    const id = {
        name: "auditorium",
        value: body.auditorium
    };
    const values = [body.auditorium, body.auditorium_name, body.auditorium_capacity, body.auditorium_type];
    next({ table, id, values });
};

const putAuditorium = async (request, response, next) => {
    const body = request.body;
    const id = {
        name: "auditorium",
        value: body.auditorium
    };
    const values = {
        auditorium_name: body.auditorium_name,
        auditorium_capacity: body.auditorium_capacity,
        auditorium_type: body.auditorium_type
    };
    next({ table, id, values });
};

const deleteAuditorium = async (request, response, next) => {
    const id = {
        name: "auditorium",
        value: request.params.auditoriumId.toString()
    };
    next({ table, id });
};

const router = express.Router();

router.get("/", getAuditoriums, crudController.getModels);
router.post("/", postAuditorium, crudController.postModel);
router.put("/", putAuditorium, crudController.putModel)
router.delete("/:auditoriumId", deleteAuditorium, crudController.deleteModel);

module.exports = router;