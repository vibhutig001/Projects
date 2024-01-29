import { Injectable } from '@angular/core';

import { HttpClient } from '@angular/common/http';

@Injectable({
  providedIn: 'root'
})
export class MarvellousService 
{

  constructor(private http : HttpClient) 
  {}

  getBatches() {
    return this.http.get<any[]>("http://localhost:5555/getBatches");
  }
  insertData()
  {
    return this.http.get<any[]>("http://localhost:5555/insertData");

  }
  DeleteData()
  {
    return this.http.get<any[]>("http://localhost:5555/DeleteData");

  }
  UpdateData()
  {
    return this.http.get<any[]>("http://localhost:5555/UpdateData");

  }
}