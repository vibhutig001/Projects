import { Component } from '@angular/core';
import { MarvellousService } from './marvellous.service';
import { OnInit } from '@angular/core';
import {MatButtonModule} from '@angular/material/button';
@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent //implements OnInit
{
  batches: any[] = [];
  buttonClicked = false;

  constructor(private service: MarvellousService) {}

  // Function to fetch data when the button is clicked
  fetchData() {
    this.service.getBatches().subscribe(data => {
      this.batches = data;
    });
    this.buttonClicked = true;
  }
  insertData() {
    this.service.insertData().subscribe(response => {
      console.log(response); // Log the response from the server
      this.fetchData(); // Refresh the data after insertion
    });
    this.buttonClicked = true;
  }
  DeleteData() {
    this.service.DeleteData().subscribe(response => {
      console.log(response); 
      this.fetchData(); 
    });
    this.buttonClicked = true;
  }
  UpdateData() {
    this.service.UpdateData().subscribe(response => {
      console.log(response); 
      this.fetchData(); 
    });
    this.buttonClicked = true;
  }
}