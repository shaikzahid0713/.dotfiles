import React, { Component } from 'react';
import { SERVER_URL } from '../constants';

class CarList extends Component {
    render() {
        const tableRows = this.state.cars.map((car, index) =>
            <tr key={index}>
                <td>{car.brand}</td>                
                <td>{car.model}</td>                
                <td>{car.year}</td>                
                <td>{car.price}</td>                
                <td>{car.color}</td>                
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
}

export default CarList;
