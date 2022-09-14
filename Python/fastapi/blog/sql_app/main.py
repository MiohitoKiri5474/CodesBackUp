from fastapi import FastAPI
from . import schemas, models
from .database import engine

app = FastAPI()

models.Base.metadata.create_all ( engine )

@app.post ( '/blog' )
def creat ( req: schemas.Blog ):
    return req
