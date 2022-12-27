import React, { Component } from 'react';
import { SERVER_URL } from '../constants';

class CarList extends Component {
    constructor(props) {
        super(props);
        this.state = { cars : [] };
    }
    
    componentDidMount() {
        fetch(SERVER_URL + 'api/cars')
        .then((response) => response.json())
        .then((responseData) => {
                this.setState({
                cars: responseData._embedded.cars,
            });
        })
        .catch(err => console.error(err));
    }

    render() {
        const tableRows = this.state.cars.map((car, index) =>
            <tr key={index}>
                <td>{car.carBrand}</td>                
                <td>{car.carModel}</td>                
                <td>{car.carYear}</td>                
                <td>{car.carPrice}</td>                
                <td>{car.carColor}</td>                
            </tr>
        );

        return (
             <div className="App">
                <table>
                    <tbody>{tableRows}</tbody>
                </table>
             </div>
        );

    }
}

export default CarList;
